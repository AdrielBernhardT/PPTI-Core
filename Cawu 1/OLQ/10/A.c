#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct orang {
    char nama[300];
    int score;
};

struct cari {
    char nama1[300];
    char nama2[300];
};

void merge(struct orang *org, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    struct orang *L = (struct orang *)malloc(n1 * sizeof(struct orang));
    struct orang *R = (struct orang *)malloc(n2 * sizeof(struct orang));

    for (int i = 0; i < n1; i++)
        L[i] = org[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = org[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (strcmp(L[i].nama, R[j].nama) < 0 || 
            (strcmp(L[i].nama, R[j].nama) == 0 && L[i].score <= R[j].score)) {
            org[k] = L[i];
            i++;
        } else {
            org[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        org[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        org[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(struct orang *org, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(org, left, mid);
        mergeSort(org, mid + 1, right);

        merge(org, left, mid, right);
    }
}

int binary_search(struct orang *org, int size, char *nama) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(org[mid].nama, nama);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int tc;
    struct orang *org = (struct orang *)malloc(sizeof(struct orang) * 16000);
    struct cari *find = (struct cari *)malloc(sizeof(struct cari) * 16000);

    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        scanf("%s %d", org[i].nama, &org[i].score);
    }

    mergeSort(org, 0, tc - 1);

    int tc2;
    scanf("%d", &tc2);
    for (int i = 0; i < tc2; i++) {
        scanf("%s %s", find[i].nama1, find[i].nama2);
    }

    for (int i = 0; i < tc2; i++) {
        int idx1 = binary_search(org, tc, find[i].nama1);
        int idx2 = binary_search(org, tc, find[i].nama2);

        if (idx1 == -1 || idx2 == -1) {
            printf("not found\n");
        } else if (idx1 == idx2) {
            printf("not valid\n");
        } else {
            int score_gap = abs(org[idx1].score - org[idx2].score);
            int board_gap = abs(idx1 - idx2);
            printf("%d %d\n", score_gap, board_gap);
        }
    }

    free(org);
    free(find);

    return 0;
}