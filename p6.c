#include <stdio.h>

void main() {
	int total, number, digit;
	total = 0;

	do {
		printf("Input number > 0: ");
		scanf("%d", &number);	
	} while (number < 0);

	while (number > 0) {
		digit = number % 10;
		number = number / 10;
		total += digit;
	};

	printf("Sum of all numbers is %d\n", total);

	main();
};