#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *db = fopen("testdata.in", "r");
    int X, page = 0, flag = 0;
    int counter;
    char kata[55000];
    fscanf(db, "%d\n", &X); 
    while (fscanf(db, "%[^#]#\n", kata) != EOF){
        page++;
        counter = 0;
        char *token = strtok(kata, " \n");
        while (token != NULL) {
            counter++;
            token = strtok(NULL, " \n");
        }
        if (counter < X){
            printf("page %d: %d word(s)\n", page, counter);
            flag = 1;
        }
    }
    fclose(db);  
    if (flag == 0){
        printf("The essay is correct\n");
    }
    
    return 0;
}