#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct mahasiswa {
    char NIM[105];
    char nama[105];
} mhs [105];

char* searchbiasa(char cari[], int n){
    bool found = false;
    for (int j = 0; j < n; j++){
        if (strcmp(cari, mhs[j].NIM) == 0){
            return mhs[j].nama;
            found = true;
            break;
        }
    }
    if (!found){
        return "N/A";
    }
}

char* binarysearch(char cari[], int kiri, int kanan){
    if (kiri > kanan){
        return "N/A";
    }
    int tengah = (kiri + kanan) / 2;
    if (strcmp(cari, mhs[tengah].NIM) == 0){
        return mhs[tengah].nama;
    }
    else if (strcmp(cari, mhs[tengah].NIM) < 0){
        return binarysearch(cari, kiri, tengah - 1);
    }
    else {
        return binarysearch(cari, tengah + 1, kanan);
    }
}

char* binarysearch2(char cari[], int kiri, int kanan){
    while(kiri<=kanan){
        int mid=(kiri+kanan)/2;
        if(strcmp(cari, mhs[mid].NIM)==0){
            return mhs[mid].nama;
        }
        else if(strcmp(cari, mhs[mid].NIM)<0){
            kanan=mid-1;
        }
        else{
            kiri=mid+1;
        }
    }
    return "N/A";
}

int main(){
    FILE* DB = fopen("testdata.in", "r");
    int n, tc;
    char cari[105];

    fscanf(DB, "%d\n", &n);
    for (int i = 0; i < n; i++){
        fscanf(DB, "%s %s\n", mhs[i].NIM, mhs[i].nama);
    }
    fscanf(DB, "%d\n", &tc);
    for (int i = 0; i < tc; i++){
        fscanf(DB, "%s\n", cari);
        // char* ketemu = searchbiasa(cari, n);
        // char* ketemu = binarysearch(cari, 0, n - 1);
        char* ketemu = binarysearch2(cari, 0, n - 1);

        printf("Case #%d: %s\n", i + 1, ketemu);
    }
    fclose(DB);
    return 0;
}