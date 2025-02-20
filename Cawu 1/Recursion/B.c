#include <stdio.h>
#include <string.h>

// Deklarasi array global untuk menyimpan angka
int angka[1000];

// Fungsi rekursi untuk menghitung dan mencetak jumlah
void rekursi(int angka[], int index, int sum, int N){
    int flag = 0; // Inisialisasi flag
    sum += angka[index]; // Tambahkan nilai angka pada index ke sum
    if (index*2 <= N){ // Jika anak kiri ada dalam batas N
        rekursi(angka, index*2, sum, N); // Panggil rekursi untuk anak kiri
        flag = 1; // Set flag menjadi 1
    }

    if (index * 2 + 1 <= N){ // Jika anak kanan ada dalam batas N
        rekursi(angka, index*2+1, sum, N); // Panggil rekursi untuk anak kanan
    }
    
    if (flag == 0){ // Jika tidak ada anak kiri (flag tetap 0)
        printf("%d\n", sum); // Cetak sum
    }
}

int main(){
    int Tc, flag;
    int N, hasil;
    scanf("%d", &Tc); // Baca jumlah kasus uji
    for (int i = 1; i <= Tc; i++){
        memset(angka, 1, sizeof(angka)); // Inisialisasi array angka dengan nilai 1
        scanf("%d", &N); // Baca nilai N
        for(int j = 1; j <= N; j++){
            scanf("%d", &angka[j]); // Baca nilai angka ke dalam array
        }
        int index = 1, sum = 0; // Inisialisasi index dan sum
        printf("Case #%d:\n", i); // Cetak nomor kasus
        rekursi(angka, index, sum, N); // Panggil fungsi rekursi
    }
    return 0; // Kembalikan 0 untuk menandakan program selesai dengan sukses
}