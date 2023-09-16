#include <stdio.h>
#include <stdlib.h>

void main() {
	int value = 0, count = 0, r = 0, isRepeated = 0;
	int arr[] = {2, 2, 4, 1, 0, 5, 6, 6, 6, 11, 2};
	int *repeated = (int *)malloc(sizeof(int) * 11);

	for (int i = 0; i < 11; i++) {
		isRepeated = 0;
		count = 0;

		for (int k = 0; k < 11; k += 2) {
			if (arr[i] == repeated[k]) {
				isRepeated = 1;
				break;
			}
		}

		if (isRepeated) {continue;}

		for (int j = 0; j < 11; j++) {
			if (arr[i] == arr[j]) {
				count++;
			}
		}

		repeated[r] = arr[i];
		repeated[r + 1] = count;

		r += 2;
	}

	for (int p = 0; p < 11; p += 2) {
		printf("%d is repeated %d times\n", repeated[p], repeated[p + 1]);
	}
}
