#include <stdio.h>
#include <string.h>

void merge(char *string, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    char L[n1 + 1], R[n2 + 1];

    for (int i = 0; i < n1; i++)
        L[i] = string[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = string[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            string[k] = L[i];
            i++;
        } else {
            string[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        string[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        string[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(char* string, int l, int r){
    if(l<r){
        int m = l+(r-l)/2;

        mergesort(string, l, m);
        mergesort(string, m+1, r);
        merge(string, l, m, r);
    }
}

void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void mergeSortString(char string[][101], int start, int end){
    if(start>=end) return; 
    int mid = start + (end-start)/2; 
    mergeSortString(string, start, mid); 
    mergeSortString(string, mid+1, end); 
    merge1(string, start, end); 
}

void merge1(char string[][1001], int start, int end){
    int mid = start + (end-start)/2; 
    int leftSize = mid-start+1; 
    int rightSize = end-mid; 
    char left[leftSize][1001], right[rightSize][1001]; 
    for(int i=0; i<leftSize; i++){
        strcpy(left[i], string[start+i]); 
    }
    for(int i=0; i<rightSize; i++){
        strcpy(right[i], string[mid+1+i]); 
    }
    int leftIndex=0, rightIndex=0, stringIndex=start; 
    while(leftIndex<leftSize && rightIndex<rightSize){
        if(strcmp(left[leftIndex], right[rightIndex])>0){
            strcpy(string[stringIndex], left[leftIndex]); 
            leftIndex++; 
        }else{
            strcpy(string[stringIndex], right[rightIndex]); 
            rightIndex++; 
        }
        stringIndex++; 
    }
    while(leftIndex<leftSize){
        strcpy(string[stringIndex], left[leftIndex]); 
        leftIndex++; 
        stringIndex++; 
    }
    while(rightIndex<rightSize){
        strcpy(string[stringIndex], right[rightIndex]); 
        rightIndex++; 
        stringIndex++; 
    }
}

void quickSortChar(char string[], int start, int end){
    if(start>=end) return; 
    char pivot = string[end]; 
    int left=start-1, right=start; 
    for(right=start; right<end; right++){
        if(string[right]<=pivot){
            left++; 
            if(left!=right){
                swap(&string[left], &string[right]); 
            }
        }
    }
swap(&string[left+1], &string[end]); 
int pivotIndex = left+1; 
quickSortChar(string, start, pivotIndex-1); 
quickSortChar(string, pivotIndex+1, end); 
}

int main(){
    int R, C;
    scanf("%d %d", &R, &C); getchar();
    char string[1001][1001];
    for(int i = 0; i < R; i++){
        scanf("%s", string[i]); getchar();
        quickSortChar(string[i], 0, C-1); 
    }

    // for(int i = 0; i < R; i++){
    //     mergesort(string[i], 0, C-1);
    //     string[i][C] = '\0';
    // }
    mergeSortString(string, 0, R-1); 
     // Print the sorted grid
    for(int i = 0; i < R; i++){
        printf("%s\n", string[i]); 
    }

    // for(int i = 0; i < R-1; i++){
    //     for(int j = 0; j < R-i-1; j++){
    //         if(strcmp(string[j], string[j+1]) < 0){
    //             char temp[C+1];
    //             strcpy(temp, string[j]);
    //             strcpy(string[j], string[j+1]);
    //             strcpy(string[j+1], temp);
    //         }
    //     }
    // }

    // // Print the sorted grid
    // for(int i = 0; i < R; i++){
    //     printf("%s\n", string[i]);
    // }

    return 0;
}