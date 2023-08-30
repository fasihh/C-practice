#include <stdio.h>

void main() {
	int num;

	printf("Input 7 digit number: ");
	scanf("%d", &num);

	switch(num) {
		case 1111110:
			printf("Floor 0");
			break;
		case 0110000:
			printf("Floor 1");
			break;
		case 1101101:
			printf("Floor 2");
			break;
		case 1111001:
			printf("Floor 3");
			break;
		case 0110011:
			printf("Floor 4");
			break;
		case 1011011:
			printf("Floor 5");
			break;
		case 1011111:
			printf("Floor 6");
			break;	
		case 1110000:
			printf("Floor 7");
			break;
		case 1111111:
			printf("Floor 8");
			break;
		case 1110011:
			printf("Floor 9");
			break;
		default: 
			main();
	};
};