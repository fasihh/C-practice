#include <stdio.h>

void main() {
	int num1, num2, num3;
	
	num1 = 6, num2 = 16, num3 = 26;

	num1 = num1 % 10;
	num2 = num2 % 10;
	num3 = num3 % 10;

	int condition = (num1 == num2) || (num1 == num3) || (num2 == num3);

	switch (condition) {
	case 1:
		printf("Same");
		break;
	case 0:
		printf("Not same");
		break;
	}
}