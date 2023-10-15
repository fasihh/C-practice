#include <stdio.h>


char *create_phone_number(char phnum[15], const unsigned char n[10])
{
	sprintf(phnum, "(%d%d%d) %d%d%d-%d%d%d%d", n[0], n[1], n[2], n[3], n[4], n[5], n[6], n[7], n[8], n[9]);

	return phnum;
}

int main() {
	char phone_number[15];

	printf("%s\n", create_phone_number(phone_number, (unsigned char[10])
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }));

	return 0;
}
