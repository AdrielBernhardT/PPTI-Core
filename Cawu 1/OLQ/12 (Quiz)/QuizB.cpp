#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Deklarasi struktur untuk menyimpan data esai
struct essay{
    int page;      // Nomor counter
    int word;      // Jumlah kata
}data[50005];      // Array untuk menyimpan hingga 50005 esai

int main(){
    // Membuka file "testdata.in" untuk dibaca
    FILE *f = fopen("testdata.in", "r");
    int minimumword, counter = 0;
    
    // Membaca jumlah kata minimum yang diperlukan dari file
    fscanf(f, "%d\n", &minimumword);
    
    // Membaca isi file hingga akhir file (EOF)
    while (!feof(f)){
        char temp[55] = {};
        
        // Membaca satu kata dari file
        fscanf(f, "%s", temp); fgetc(f);
        
        // Jika kata tersebut adalah "#", berarti counter baru
        if (strcmp(temp, "#") == 0){
            data[counter].page = counter + 1; // Menyimpan nomor counter
            counter++;                  // Pindah ke counter berikutnya
        } else {
            data[counter].word++;       // Menambah jumlah kata di counter saat ini
        }
    }

    int flag = 1, arr[counter + 1] = {};
    
    // Inisialisasi array arr dengan nilai -1
    for (int j = 0; j < counter; j++){
        arr[j] = -1;
    }
    
    // Memeriksa setiap counter apakah jumlah katanya kurang dari n
    for (int j = 0, k = 0; j < counter; j++){
        if (data[j].word < minimumword){
            flag = 0;       // Menandai bahwa ada counter yang tidak memenuhi syarat
            arr[k] = j;     // Menyimpan indeks counter yang tidak memenuhi syarat
            k++;
        }
    }
    
    // Jika ada counter yang tidak memenuhi syarat
    if (!flag){
        for (int j = 0; j < counter; j++){
            if (arr[j] >= 0){
                // Mencetak nomor counter dan jumlah kata yang tidak memenuhi syarat
                printf("page %d: %d word(s)\n", data[arr[j]].page, data[arr[j]].word);
            }
        }
    } else {
        // Jika semua counter memenuhi syarat
        printf("The essay is correct\n");
    }
    
    // Menutup file
    fclose(f);
    return 0;
}