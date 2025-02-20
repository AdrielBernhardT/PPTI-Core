#include <stdio.h>

int arr[1005];  // Array untuk menyimpan bilangan Fibonacci (memoization)

int fib(int n) {
    // Jika sudah pernah dihitung, kembalikan hasil yang tersimpan
    if (arr[n] != -1) {
        return arr[n];
    }

    // Menghitung bilangan Fibonacci dengan rekursi dan menyimpan hasilnya
    arr[n] = fib(n - 1) + fib(n - 2);
    return arr[n];
}

int main() {
    int F0, F1, K;
    
    // Baca nilai F0, F1, dan K
    scanf("%d %d", &F0, &F1);
    scanf("%d", &K);

    // Inisialisasi array Fibonacci dengan -1 (untuk memeriksa apakah sudah dihitung)
    for (int i = 0; i <= 1000; i++) {
        arr[i] = -1;
    }

    // Inisialisasi dua nilai awal Fibonacci
    arr[0] = F0;
    arr[1] = F1;

    // Hitung Fibonacci ke-K
    int result = fib(K);

    // Tampilkan hasil
    printf("%d\n", result);

    return 0;
}
