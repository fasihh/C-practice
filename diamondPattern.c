#include <stdio.h>

#define ch "*"

void diamondPattern(int);

int main() {
	diamondPattern(3);

	return 0;
}

void diamondPattern(int n) {
	int r = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			printf(ch);
		}

		for (int k = 0; k < 2*r - 1; k++) {
			printf(" ");
		}
		if (i) printf(" ");

		for (int q = 0; q < n - i; q++) {
			printf(ch);
		}

		printf("\n");
		r++;
	}
	r -= 2;

	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < n - i + 1; j++) {
			printf(ch);
		}

		for (int k = 0; k < 2*r - 1; k++) {
			printf(" ");
		}
		if (i - 1) printf(" ");

		for (int q = 0; q < n - i + 1; q++) {
			printf(ch);
		}

		r--;
		printf("\n");
	}
}