#include <stdio.h>
#include <math.h>

int getHex(int num) {
	switch (num) {
			case 10:
				return 65;
			case 11:
				return 66;				
			case 12:
				return 67;
			case 13:
				return 68;
			case 14:
				return 69;
			case 15:
				return 70;
	}
	return num;
}

int binToNum(int num) {
	int count = 0, total = 0;

	while (num) {
		if (num % 10) { 
			total += pow(2, count);
		}

		num /= 10;
		count++;
	}

	return total;
}

void hexToNum(char num[], int mask) {
	int total = 0;

	for (int i = 0; i < mask; i++) {
		total += pow(16, i);
	}

	printf("%d", total);
}

void numToBin(int num, int mask) {
	mask = ~(1 << mask);
	while (mask) {
		printf("%d", num & mask && 1);
		mask >>= 1;
	}
}

void numToHex(int num) {
	int group = 0, mask = 15 * pow(2, 16);

	while (mask) {
		group = num & mask;

		if (group > 15) {
			group >>= 4;
		}

		(group < 10) ? printf("%d", group) : printf("%c", getHex(group));

		//total >>= 4;
		mask >>= 4;
	}
}

void main() {
	int num;
	int mask;

	printf("Number to convert: ");
	scanf("%d", &num);

	printf("\n");

	numToHex(num);

	printf("\n");

	main();
}

void achtBits(int value) {
	printf("%d%d%d%d%d%d%d%d", 
		value & 128 && 1,
		value & 64 && 1,
		value & 32 && 1,
		value & 16 && 1,
		value & 8 && 1,
		value & 4 && 1,
		value & 2 && 1,
		value & 1 && 1
	);
}