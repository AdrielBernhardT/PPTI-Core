#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int ID;
    char Name[50];
    int price;
} item[1005];

int counter = 0;

void simpan(){
    FILE* db = fopen("productlist.csv", "w");

    for (int i = 0; i < counter; i++){
        fprintf(db, "%d#%s#%d\n", item[i].ID, item[i].Name, item[i].price);
    }
    fclose(db);
}

void load(){
    FILE* db = fopen("productlist.csv", "r");

    if(db == NULL){
        printf("Error loading file...\n");
    }

    counter = 0;
    while (fscanf(db, "%d#%[^#]#%d\n", &item[counter].ID, item[counter].Name, &item[counter].price) != EOF){
        counter++;
    }

    fclose(db);
}


int search(int id){
    for (int i = 0; i < counter; i++){
        if (item[i].ID == id){
            return i;
        }
    }
    return -1;
}

void input(){
    struct product newItem;
    do{
        printf("Name: ");
        scanf("%[^\n]", newItem.Name); getchar();
        if (strlen(newItem.Name) < 5 || strlen(newItem.Name) > 50){
            printf("Name must be 5-50 characters\n");
        }
    } while (strlen(newItem.Name) < 5 || strlen(newItem.Name) > 50);
    
    do{
        printf("Price: ");
        scanf("%d", &newItem.price); getchar();
        if (newItem.price < 1000 || newItem.price > 1000000){
            printf("Price must be between 1000 and 1000000\n");
        }
    } while (newItem.price < 1000 || newItem.price > 1000000);
    
    newItem.ID = counter + 1;

    char validation;
    do {
        printf("Add this product? (Y/N): ");
        scanf("%c", &validation); getchar();
        if (validation != 'Y' && validation != 'N'){
            printf("Invalid input\n");
        }
    } while (validation != 'Y' && validation != 'N');

    if (validation == 'Y'){
        item[counter] = newItem;
        counter++;
        simpan();
    } else {
        printf("Product canceled\n");
    }
}

void view(){
    printf("Counter: %d\n", counter);
    if (counter == 0){
        printf("No product available\n");
    } else {
        printf("Product List\n");
        for (int i = 0; i < counter; i++){
            printf("ID: %d, Name: %s, Price: %d\n", item[i].ID, item[i].Name, item[i].price);
        }
    }
}

void update(){
    int id;
    int newPrice;

    printf("Enter product ID: ");
    scanf("%d", &id); getchar();

    int index = search(id);

    if (index != -1){
        printf("Current Price: %d\n", item[index].price);
        printf("New Price: ");
        scanf("%d", &newPrice); getchar();

        item[index].price = newPrice;

        simpan();
    } else {
        printf("Product not found!\n");
    }
}

void swap(struct product *a, struct product *b){
    struct product temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int low, int high){
    int pivot = item[high].price;
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (item[j].price < pivot){
            i++;
            swap(&item[i], &item[j]);
        }
    }

    swap(&item[i + 1], &item[high]);
    return i + 1;
}

void quickSort(int low, int high){
    if (low < high){
        int pi = partition(low, high);

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void sort(){
    if (counter == 0)
    {
        printf("No product available\n");
    } else {
        quickSort(0, counter - 1);
        printf("Product sorted by price\n");
    }
    simpan();
}

int main(){
    int choice;
    do {
        load();
        printf("1. Add Product\n");
        printf("2. View Product\n");
        printf("3. Update Product\n");
        printf("4. Sort by Price\n");
        printf("5. Exit\n");
        printf(">> ");
        scanf("%d", &choice); getchar();
        if (choice == 1) {
           input();
        } else if (choice == 2) {
            view();
        } else if (choice == 3) {
            update();
        } else if (choice == 4) {
            sort();
        }
    } while (choice != 5);
    return 0;
}