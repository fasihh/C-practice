#include <stdio.h>

int main() {
	int arr[8] = {2, 4, 2, 3, 5, 5, 4, 4};
	int freq[100] = {0};
	int max = 1 << 31;

	for (int i = 0; i < 8; i++) {
		if (max < arr[i]) max = arr[i];
		freq[arr[i]]++;
	} 

	for (int j = 0; j <= max; j++) {
		if (!freq[j]) continue;
		printf("Frequency of %d = %d\n", j, freq[j]);
	}
	printf("\n");

	return 0;
}