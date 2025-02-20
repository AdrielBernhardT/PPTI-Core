#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

struct DataBase {
    char ID[10];
    char Name[25];
    char Category[10];
    int Stock;
    int Price;
} DB[1005];

struct tempdata {
    char ID[10];
    char Name[25];
    char Category[10];
    int Stock;
    int Price;
} TD;

int counter = 0;

void ETC(){
    printf("Enter to continue...");
    getchar();
}

// Update Read
void updatedata(){
    FILE *fp = fopen("candy.txt", "r");
    counter = 0;
    while (!feof(fp)){
        fscanf(fp, "%[^#]#%[^#]#%[^#]#%d#%d\n", DB[counter].ID, DB[counter].Name, DB[counter].Category, &DB[counter].Stock, &DB[counter].Price);
        counter++;
    }
    fclose(fp);
}

// Create
void CreateItem(){
    srand(time(NULL));
    // Name
    do{
        printf("Input Candy Name: ");
        scanf("%[^\n]", TD.Name); getchar();
        if (strlen(TD.Name) < 8 || strlen(TD.Name) > 20){
            printf("Candy name must be 8-20 characters\n");
        }
    } while (strlen(TD.Name) < 8 || strlen(TD.Name) > 20);

    // Category
    do{
        printf("Input Candy Category [Choco/Gummy/Minty/Fruity]: ");
        scanf("%[^\n]", TD.Category); getchar();
        if (strcmp(TD.Category, "Choco") != 0 && strcmp(TD.Category, "Gummy") != 0 && strcmp(TD.Category, "Minty") != 0 && strcmp(TD.Category, "Fruity") != 0){
            printf("Candy Category must be [Choco/Gummy/Minty/Fruity]\n");
        }
    } while (strcmp(TD.Category, "Choco") != 0 && strcmp(TD.Category, "Gummy") != 0 && strcmp(TD.Category, "Minty") != 0 && strcmp(TD.Category, "Fruity") != 0);
    
    // Stock
    do{
        printf("Input Candy Stock: ");
        scanf("%d", &TD.Stock); getchar();
        if (TD.Stock < 1){
            printf("Candy Stock must be more than 0\n");
        }
    } while (TD.Stock < 1);

    // Price
    do{
        printf("Input Candy Price: ");
        scanf("%d", &TD.Price); getchar();
        if (TD.Price <= 0){
            printf("Candy Price must be more than 0\n");
        }
    } while (TD.Price <= 0);

    // ID
    for (int i = 0; i < 5; i++){
        if (i < 2)
        {
            TD.Name[i] = TD.ID[i];
        } else {
            TD.ID[i] = (rand() % 2) + '0';
        }
    }

    // Import File
    FILE *fp = fopen("candy.txt", "a");
    fprintf(fp, "%s#%s#%s#%d#%d\n", TD.ID, TD.Name, TD.Category, TD.Stock, TD.Price);
    fclose(fp);
}

void merge(int l,int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    struct DataBase L[n1], R[n2];
    for (int i = 0; i < n1; i++){
        L[i] = DB[l+i];
    }
    for (int i = 0; i < n2; i++){
        R[i] = DB[m+1+i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2){
        if (strcmp(L[i].Name, R[j].Name) >= 0){
            DB[k] = L[i];
            i++;
        } else {
            DB[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        DB[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        DB[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int l, int r){
    if (l<r) {
        int m = l+(r-l)/2;
        mergesort(l, m);
        mergesort(m+1, r);
        merge(l, m, r);
    } 
}

typedef enum ViewBy {Gummy, Choco, Minty, Fruity, All} Mode;
const char col[6][10] = {"Gummy", "Choco", "Minty", "Fruity", "All"};

Mode GetMode (char* x){
    for (int i = 0; i < 5; i++) {
        if (strcmp(x, col[i]) == 0){
            return (Mode)i;
        }
    }
}

void ViewItem(){
    updatedata();

    // mergesort(0, counter-1);

    printf("View Category Mode: \n");
    printf("1. Gummy\n");
    printf("2. Choco\n");
    printf("3. Minty\n");
    printf("4. Fruity\n");
    printf("5. All\n");

    int choice;
    do {
        printf(">> ");
        scanf("%d", &choice); getchar();
        if (choice <= 0 || choice > 5){
            printf("Input must be [1-5]\n");
        }
    } while (choice <= 0 || choice > 5);

    printf("ID\tName\tCategory\tStock\tPrice\n");

    for (int i = 0; i < counter; i++)
    {
        if (choice == 1 && strcmp(DB[i].Category, "Gummy") == 0){
            printf("%s\t%s\t%s\t%d\t%d\n", DB[i].ID, DB[i].Name, DB[i].Category, DB[i].Stock, DB[i].Price);
        } else if (choice == 2 && strcmp(DB[i].Category, "Choco") == 0){
            printf("%s\t%s\t%s\t%d\t%d\n", DB[i].ID, DB[i].Name, DB[i].Category, DB[i].Stock, DB[i].Price);
        } else if (choice == 3 && strcmp(DB[i].Category, "Minty") == 0){
            printf("%s\t%s\t%s\t%d\t%d\n", DB[i].ID, DB[i].Name, DB[i].Category, DB[i].Stock, DB[i].Price);
        } else if (choice == 4 && strcmp(DB[i].Category, "Fruity") == 0){
            printf("%s\t%s\t%s\t%d\t%d\n", DB[i].ID, DB[i].Name, DB[i].Category, DB[i].Stock, DB[i].Price);
        } else if (choice == 5){
            printf("%s\t%s\t%s\t%d\t%d\n", DB[i].ID, DB[i].Name, DB[i].Category, DB[i].Stock, DB[i].Price);
        }
    }
    counter = 0;
}

void BuyItem(){
    updatedata();
    printf("Candy Name:");
    char name[25];
    scanf("%[^\n]", name); getchar();
    for(int i = 0; i < counter; i++){
        if(strcmp(DB[i].Name, name) == 0){
            printf("Input Amount: ");
            int amount;
            scanf("%d", &amount); getchar();
            if(amount > DB[i].Stock){
                printf("Stock is not enough\n");
            } else {
                DB[i].Stock -= amount;
                FILE *fp = fopen("candy.txt", "w");
                for (int j = 0; j < counter; j++){
                    fprintf(fp, "%s#%s#%s#%d#%d\n", DB[j].ID, DB[j].Name, DB[j].Category, DB[j].Stock, DB[j].Price);
                }
                fclose(fp);
                printf("Buy Success\n");
            }
            return;
        }
    }
    printf("Candy not found\n");
    counter = 0;
}

int main(){
    int choice;
    do {
        do {
            printf("YupI Store\n");
            printf("1. Create\n");
            printf("2. View\n");
            printf("3. Buy Candy\n");
            printf("4. Exit\n");
            printf(">> ");
            scanf("%d", &choice); getchar();
            if(choice <= 0 || choice > 4){
                printf("Input must be [1-4]\n"); 
                ETC();
                system("cls");
            }
        } while (choice <= 0 || choice > 4);
        
        if(choice == 1){
            CreateItem();
            ETC();
        } else if (choice == 2){
            ViewItem();
            ETC();
        } else if (choice == 3){
            BuyItem();
            ETC();
        }
    } while (choice != 4);
    return 0;
}