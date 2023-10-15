#include <stdio.h>
#include <string.h>

void displayPattern(char *binary) {
	int i = 0, j = 0, n = strlen(binary);
	char ch = 65;

	while (i < n) {
		if (i % 2) {
			j = 0;
			while (j++ < i + 1) {
				if (*binary == '\0') {
					printf("%c ", *(binary - 1));
				} else {
					printf("%c ", *binary++);
				}
			}
			printf("\n");
		} else {
			j = 0;
			while (j++ < i + 1) {
				printf("%c ", ch);
			}
			printf("\n");
			ch += 2;
		}

		i++;
	}
}

int main() {
	displayPattern("11111001");
	int x;
 
	 for(x=-1; x<=20; x++)
	 {
	 if(x < 10)
	 continue;
	 else
	 break;
	 printf("Never give up!!!");
	}

	return 0;
}