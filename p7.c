#include <stdio.h>

int isValid(int, int, int);
void doDateDiff(int*, int*);
void doMonthDiff(int*, int*);

void main() {
	int date, month, year, birthDate, birthMonth, birthYear, valid, 
	dateDiff, monthDiff, yearDiff = 0;

	do {
		printf("Input valid current date, month and year: ");
		scanf("%d %d %d", &date, &month, &year);
		valid = isValid(date, month, year);
	} while (!valid);
	
	do {
		printf("Input valid birth date, month, year: ");
		scanf("%d %d %d", &birthDate, &birthMonth, &birthYear);
		valid = isValid(birthDate, birthMonth, birthYear);

		if (birthYear > year) {
			valid = 0;
		};

		if (birthYear == year && birthMonth > month) {
			valid = 0;
		};

		if (birthYear == year && birthMonth == month && birthDate > date) {
			valid = 0;
		};
		
	} while (!valid);

	dateDiff = date - birthDate;
	monthDiff = month - birthMonth;
	yearDiff = year - birthYear;

	 // correct date offset
	doDateDiff(&dateDiff, &monthDiff);

	// correct month offset
	doMonthDiff(&monthDiff, &yearDiff);

	printf("%d year(s), %d month(s) and %d day(s) old\n\n", yearDiff, monthDiff, dateDiff);

	main();
};

int isValid(int date, int month, int year) {
	if (date > 31 || date < 0 || month > 12 || month < 0 || year < 0) {return 0;};
	if ((month == 4 || month == 6 || month == 9 || month == 11) && date > 30) {return 0;};

	int isLeap = year % 4 == 0 || year % 400 == 0 && year % 100 != 0;

	if (isLeap) {
		if (date > 29 && month == 2) {
			return 0;
		};
	} else {
		if (date > 28 && month == 2) {
			return 0;
		};
	};
	return 1;
};

void doDateDiff(int* dateDiff, int* monthDiff) {
	if (*dateDiff < 0) {
		*dateDiff += 31;
		*monthDiff -= 1;
	};
};

void doMonthDiff(int* monthDiff, int* yearDiff) {
	if (*monthDiff < 0) {
		*monthDiff += 12;
		*yearDiff -= 1;
	};
};