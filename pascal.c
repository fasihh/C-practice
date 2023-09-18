#include <stdio.h>

void pascalsTriangle(int);
int pascalsNumber(int, int);
int factorial(int, int);

void main() {
	pascalsTriangle(12);
}

void pascalsTriangle(int size) {
	int i, col, row;
	float padding;

	row = 0, col = 1, i = 0, padding = 6;

	while (row <= size) {

		i = 0;
		while (i < size - row) {
			printf("   ");
			i++;
		}
		printf("%d", 1);

		i = 1;
		if (row) {
			while (i <= row) {
				printf("% *d", (int) padding, pascalsNumber(row, i));
				i++;
			}
		}
		
		printf("\n");

		row++;
	}
	printf("\n");
}


int pascalsNumber(int n, int k) {
	return factorial(n, 1) / (factorial(k, 1) * factorial(n - k, 1));
}


int factorial(int num, int total) {
	if (num > 0) {
		total *= num;
		return factorial(num - 1, total);
	}
	return total;
}

