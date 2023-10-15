#include <stdio.h>

void squarePattern(int n) {
	int i = 0, r = 0;
	while (i < n) {
		r = 0;
		while (r <= i) {
			printf("%d ", n - r++);
		}

		r = i;
		while (++r < n) {
			printf("%d ", n - i);
		}

		r = 0;
		while (++r < n - i) {
			printf("%d ", n - i);
		}

		r = n - i;
		while (r < n) {
			printf("%d ", ++r);
		}

		printf("\n");

		i++;
	}

	i = 0;
	while (++i < n) {
		r = 0;
		while (r < n - i) {
			printf("%d ", n - ++r + 1);
		}

		r = 0;
		while (r++ < i) {
			printf("%d ", i + 1);
		}

		while (--r) {
			printf("%d ", i + 1);
		}

		r = i;
		while (n - ++r) {
			printf("%d ", r + 1);
		}

		printf("\n");
	}
}

int main() {
	squarePattern(4);
	printf("\n");

	return 0;
}
