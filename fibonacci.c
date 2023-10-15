#include <stdio.h>

int fibonacci(int, int, int, int);

void main() {
	fibonacci(1, 0, 1, 10);
}

int fibonacci(int num1, int num2, int answer, int n) {
	if (n) {
		printf("%d  ", answer);
		return fibonacci(num2, answer, answer + num2, n - 1);
	}
	return n;
}