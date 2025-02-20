#include <stdio.h>
#include <string.h>

struct profile{
    char label[7];
    int rating;
    int diff;
    char name[11];
} player[10005];

void merge(int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    struct profile L[n1], R[n2];
    for (int i = 0; i < n1; i++){
        L[i] = player[l + i];
    }
    for (int i = 0; i < n2; i++){
        R[i] = player[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2){
        if (L[i].rating > R[j].rating){
            player[k] = L[i];
            i++;
        } else if (L[i].rating == R[j].rating){
            if (strcmp(L[i].name, R[j].name) < 0){
                player[k] = L[i];
                i++;
            } else {
                player[k] = R[j];
                j++;
            }
        } else {
            player[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        player[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        player[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int l, int r){
    if (l < r){
        int m = l + (r - l) / 2;
        mergesort(l, m);
        mergesort(m + 1, r);
        merge(l, m, r);
    }
}


int main(){
    long long int tc, mean = 0;
    scanf("%lld", &tc); getchar();
    for (long long int c = 1; c <= tc; c++){
        scanf("%d %s", &player[c].rating, player[c].name);
        mean += player[c].rating;
    }
    mean /= tc;
    for (long long int c = 1; c <= tc; c++){
        player[c].diff = (player[c].rating - mean);
        if (player[c].rating <= 200){
            strcpy(player[c].label, "Ascend");
        } else if (player[c].rating <= 350){
            strcpy(player[c].label, "Mortal");
        } else {
            strcpy(player[c].label, "Radial");
        }
    }

    // for (long long int c = 1; c <= tc; c++){
    //     printf("%s %d %d %s\n", player[c].label, player[c].rating, player[c].diff, player[c].name);
    // }

    mergesort(1, tc);

    for (long long int c = 1; c <= tc; c++){
        printf("%s %d %d %s\n", player[c].label, player[c].rating, player[c].diff, player[c].name);
    }
    return 0;
}

/*
5
500 Darren
150 Felix
150 Ethan 
50 Louis
150 Nice
*/

/*
7
150 Nathan
100 Madison
400 Katherine
350 Emma
250 Liam
100 Wendy
250 Pratt
*/