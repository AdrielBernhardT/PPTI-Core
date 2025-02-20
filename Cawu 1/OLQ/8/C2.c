#include <stdio.h>
#include <string.h>

unsigned long long modPow(int exp, int mod) {
    unsigned long long result = 1;
    unsigned long long b = 101;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * b) % mod;
        }
        b = (b * b) % mod;
        exp /= 2;
    }
    
    return result;
}

int main() {
    FILE *file = fopen("testdataC.in", "r");

    char line[101];
    int counter = 0;
    while (!feof(file)) {
        fscanf(file, "%[^\n]\n", line);
        int len = strlen(line);
        if (line[0] == ';') counter++;

        for (int i = 1; i < len; i++) {
            if (line[i - 1] == ';' && line[i] == ';') {
                counter++;
            }
        }
    }

    unsigned long long possibilities = modPow(counter, 1000000007);
    printf("%llu\n", possibilities);
}