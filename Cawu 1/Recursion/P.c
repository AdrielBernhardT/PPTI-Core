#include <stdio.h>

int arr[1005];  // Array untuk menyimpan bilangan Fibonacci (memoization)

int fib(int n) {
    // Jika sudah pernah dihitung, kembalikan hasil yang tersimpan
    if (arr[n] != -1) {
        return arr[n];
    }

    // Base cases for Fibonacci sequence
    if (n == 0) {
        return arr[n] = 0;
    } else if (n == 1) {
        return arr[n] = 1;
    } else {
        if (n%2 == 1) {
            return 1;
        } else {
            return arr[n] = fib(n - 1) + fib(n - 2);
        }
    }
}

int main() {
    int K;
    
    scanf("%d", &K);

    // Inisialisasi array Fibonacci dengan -1 (untuk memeriksa apakah sudah dihitung)
    for (int i = 0; i <= 1000; i++) {
        arr[i] = -1;
    }

    // Hitung Fibonacci ke-K
    int result = fib(K);

    // Tampilkan hasil
    printf("%d\n", result);

    return 0;
}
