#include <stdio.h>
#include <stdlib.h>

void findMagicNumber(int[], int[], int, int);
void initializeList(int[], int);
void insertionSort(int[], int);

void main() {
	int n, amount;

	printf("taxi-cab numbers within a grid of 'n x n' dimensions: ");
	scanf("%d", &n);

	printf("Amount of taxi-cab numbers to be printed: ");
	scanf("%d", &amount);

	printf("\n");

	int *numList = (int *)malloc(sizeof(int) * n * n);
	int *magicNum = (int *)malloc(sizeof(int));

	initializeList(numList, n);

	findMagicNumber(magicNum, numList, n, amount);

	free(numList);
	free(magicNum);

	printf("\n");
} // end main()


void findMagicNumber(int magicNum[], int list[], int n, int amount) {
	int value = 0, size = sizeof(int), m = 0;

	// selecting
	for (int y = 5; y < n; y++) {
		for (int x = 5; x < n; x++) {
			// select each value
			value = *(list + y*n + x); 

			// matching
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {

					// ignore equals
					if (x == j && y == i || y == j && x == i) {
						continue;
					}

					// return magic number
					if (value == *(list + i*n + j)) {
						size += sizeof(int);
						int *new_magicNum = (int *)realloc(magicNum, size);

						*(new_magicNum + m) = value;
						m++; 

						magicNum = new_magicNum;
					}
				} // inner loop of matching
			} // outer loop of matching

		} // inner loop of selection
	} // outer loop of selection

	// showing magic numbers 

	insertionSort(magicNum, m); // sorting to get correct order

	// printing only one number out of the repetitions
	for (int i = 0; i < n; i++) {
		if (magicNum[i] == 0) {continue;}

		if (!amount) {
			break;	
		}

		printf("%d ", magicNum[i]);
		amount--;

		for (int j = i + 1; j < n; j++) {
			if (magicNum[j] == magicNum[i]) {
				magicNum[j] = 0;
			}
		} 
	}
} // end magicNumbers()


void initializeList(int list[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			*(list + i*n + j) = (i * i * i) + (j * j * j);
		}
	}
} // end initializeList()

void insertionSort(int numberList[], int len) {
	int j, i, temp;

	for(i = 0; i < len; i++) {
		j = i;
		while(j > 0 && numberList[j] < numberList[j - 1]) {
			temp = numberList[j];
			numberList[j] = numberList[j - 1];
			numberList[j - 1] = temp;

			j--;
		}
	}
}
