#include <stdio.h>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int bag[100], remove[100];
	for (int i = 0; i < N; i++) {
		scanf("%d", &bag[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &remove[i]);
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (bag[j] == remove[i]) {
				bag[j] = -1; // Mark as removed
			}
		}
	}

	int max = -1;
	for (int i = 0; i < N; i++) {
		if (bag[i] != -1 && bag[i] > max) {
			max = bag[i];
		}
	}

	if (max == -1) {
		printf("Maximum number is -1\n");
	} else {
		printf("Maximum number is %d\n", max);
	}

	return 0;
}