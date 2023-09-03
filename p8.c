#include <stdio.h>

void main() {
	int total, count, number;
	total = 0;
	count = 0;

	do {
		printf("Input number (enter 0 to terminate): ");
		scanf("%d", &number);

		if (number != 0) {
			total += number;
			count++;
			continue;
		};
		break;
	} while (1);

	if (count == 0) {
		printf("Average is 0");
	} else {
		printf("Avergae is %d", total/count);
	};

	main();
};