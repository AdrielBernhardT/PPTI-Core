#include <stdio.h>
#include <string.h>

int main(){
    char words[105];
    long long int posibilities = 1; 

    FILE *db = fopen("testdata.txt", "r"); // Open File

    while (!feof(db)){
        fscanf(db, "%s", words); // Read File
        int len = strlen(words), counter =  0;

        if (words[0] == ';') {  // if first character is ';'
            counter++;
        }

        for (int i = 1; i < len; i++) { // Loop through the words
            if (words[i - 1] == ';' && words[i] == ';') { // if two consecutive character is ';'
                counter++;
            }
        }

        for (int i = 0; i < counter; i++) { // Calculate the possibilities
            posibilities *= 101;
            posibilities %= 1000000007; 
        }
        
        printf("%lld\n", posibilities); // Print the possibilities
    }
    return 0;
}