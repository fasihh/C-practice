#include <stdio.h>

void lightBulbPattern(int);

int main() {
	lightBulbPattern(4);
	return 0;
}

void lightBulbPattern(int n) {
	int r;

	int i = 0;
	while (++i <= n) {

		r = 1;
		int j = 0;
		while (j <= i) {

			int k = 0;
			while (k++ < n - j) {
				printf(" ");
			}

			k = 0;
			while (k++ < r) {
				printf("!");
			}

			r += 2;
			j++;
			printf("\n");
		}
	}
	printf("\n\n");
}