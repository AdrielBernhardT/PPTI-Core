#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

struct itemlist {
    char name[100];
    int price;
    int stock;
} list [1005];

int counter = 0;

void createItem() {
    FILE *fp = fopen("iniFile.csv", "a");

    if (fp == NULL) {
        puts("GA ADA FILENYA GOBLOK!\n");
        return;
    }

    printf("Enter Item name: ");
    scanf("%[^\n]", list[counter].name); getchar();
    printf("Input Item price: ");
    scanf("%d", &list[counter].price); getchar();
    printf("Input Item stock: ");
    scanf("%d", &list[counter].stock); getchar();

    fprintf(fp, "%s#%d#%d\n", list[counter].name, list[counter].price, list[counter].stock);
    counter++;
    fclose(fp);
}

void viewItem() {
    FILE *fp = fopen("iniFile.csv", "r");
    if (!fp) {
        puts("GA ADA FILENYA GOBLOK!\n");
        return;
    }
    int idx = 0;
    while (idx != counter) {
        printf("Name: %s\nPrice: %d\nStock: %d\n", list[idx].name, list[idx].price, list[idx].stock);
        printf("\n");
        idx++;
    }
    fclose(fp);
}

void deleteItem() {
    FILE *fp = fopen("iniFile.csv", "r");
    if (!fp) {
        puts("GA ADA FILENYA GOBLOK!\n");
        return;
    }

    char todelete[100];
    printf("Enter Item name to delete: ");
    scanf("%[^\n]", todelete); getchar();

    bool found = 0;

    struct itemlist hapus;
    int idx = 0;
    // while (idx != counter) {
    //     printf("Name: %s\nPrice: %d\nStock: %d\n", list[idx].name, list[idx].price, list[idx].stock);
    //     printf("\n");
    //     idx++;
    // }
    // while (idx < counter) {
    //     if (strcmp(list[idx].name, todelete) == 0) {
    //         strcpy(hapus.name, list[idx].name);
    //         hapus.price = list[idx].price;
    //         hapus.stock = list[idx].stock;
    //         found = 1;
    //     } else {

    //     }
    //     idx++;
    // }
    fclose(fp);

    if (found) {
        FILE *fp = fopen("iniFile.csv", "w");
        for (int i = 0; i < counter; i++) {
            fprintf(fp, "%s#%d#%d\n", item[i].name, item[i].price, item[i].stock);
        }
        fclose(fp);
        printf("%s %d %d\n", hapus.name, hapus.price, hapus.stock);
        printf("Has been deleted\n");
    } else {
        printf("Item not found\n");
    }

    counter = 0;
}

int main(){
    int choice;
    do
    {
        printf("1. Create Item\n");
        printf("2. View Item\n");
        printf("3. Delete Item\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &choice); getchar();

        if (choice == 1) {
            createItem();
        } else if (choice == 2) {
            viewItem();
        } else if (choice == 3) {
            deleteItem();
        }
    } while (choice != 4);


    return 0;
}