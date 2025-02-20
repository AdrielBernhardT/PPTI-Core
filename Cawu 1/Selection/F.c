#include <stdio.h>

void menukar(int arr[], int n) {
    int temp;
    int tuker;
    for (int i = 0; i < n - 1; i++) {
        tuker = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                tuker = 1;
            }
        }
        if (tuker == 0) {
            break;
        }
    }
}

int main() {
    int daging, sayur, telur;
    scanf("%d %d %d", &daging, &sayur, &telur);
    int arr[] = {daging, sayur, telur};
    int n = sizeof(arr) / sizeof(arr[0]);
    menukar(arr, n);

    if (arr[0] == daging && arr[1] == sayur && arr[2] == telur) {
        printf("Daging\nSayur\nTelur\n");
    } else if (arr[0] == daging && arr[1] == telur && arr[2] == sayur) {
        printf("Daging\nTelur\nSayur\n");
    } else if (arr[0] == telur && arr[1] == daging && arr[2] == sayur) {
        printf("Telur\nDaging\nSayur\n");
    } else if (arr[0] == telur && arr[1] == sayur && arr[2] == daging) {
        printf("Telur\nSayur\nDaging\n");
    } else if (arr[0] == sayur && arr[1] == daging && arr[2] == telur) {
        printf("Sayur\nDaging\nTelur\n");
    } else if (arr[0] == sayur && arr[1] == telur && arr[2] == daging) {
        printf("Sayur\nTelur\nDaging\n");
    }
    return 0;
}
