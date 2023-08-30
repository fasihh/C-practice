#include <stdio.h>

void main() {
	int num;

	do {
		printf("Input any number above 0: ");
		scanf("%d", &num);
	}
	while (num <= 0); 

	if (num % 2 == 0) {
		printf("Number is even");
	} else {
		printf("Number is odd");
	};
};
