#include <stdio.h>

int factorial(int, int);

int main() {

	printf("%d\n", factorial(5, 1));

	return 0;
}

int factorial(int num, int ans) {
	if (num > 0) {
		return factorial(--num, ans*num);
	} else {
		return ans;
	}

}