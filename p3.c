#include <stdio.h>

void main() {
	int age;
	int* agePtr = &age;
	char gender;
	char* genderPtr = &gender;

	printf("Input age and gender: ");
	scanf("%d %c", agePtr, genderPtr);

	if (*genderPtr == 'm' && *agePtr >= 18 || *genderPtr == 'f' && *agePtr >= 16) {
		printf("Adult");
	} else {
		printf("Minor");
	};
};
