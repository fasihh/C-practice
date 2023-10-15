#include <stdio.h>

void insertionSort(int[], int);
int binarySearch(int[], int, int, int);

int main() {
	int status;
	int value = 2;
	int numberList[] = {19, 5, 42, 2, 77};

	insertionSort(numberList, 5);

	for(int i = 0; i < sizeof(numberList)/sizeof(numberList[0]); i++) {
		printf("%d ", numberList[i]);
	}

	status = binarySearch(numberList, value, 0, 5);

	if (status) { 
		printf("\nExists");
		return 1;
	}

	printf("\nDoes not exist");
	return 0;
}


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

int binarySearch(int numberList[], int value, int start, int end) {
	int mid = (start + end)/2;

	if (start <= end) {
		if (numberList[mid] == value) {
			return 1;
		} else if (value > numberList[mid]) {
			return binarySearch(numberList, value, mid + 1, end);
		} else if (value < numberList[mid]) {
			return binarySearch(numberList, value, start, mid - 1);
		}
	}

	return 0;
}
