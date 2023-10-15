#include <stdio.h>

void pattern(int);

void main() {
	//pattern(1113);

	switch(10) {
		case 5+5:
			printf("test");
	}

}

void pattern(int n) {
	printf("%d%d%d%d", n % 10 * 20, n / 10 % 10 * 20, n / 100 % 10 * 20, n / 1000 * 20);
}