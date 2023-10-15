#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool IsIsogram(const char *);

int main() {
	printf("%d", IsIsogram("aA"));

	return 0;
}

bool IsIsogram (const char *string) 
{
  	if(!strlen(string)) return true;
  
  	int i = -1;
  	while (string[++i]) {
	  	char ch1 = tolower(string[i]);

    	int j = -1;
	    while (string[++j]) {
	      	if (j == i) {continue;}

	      	char ch2 = tolower(string[j]);
	      	if (ch1 == ch2) {return false;}
	    }
	}
	return true;
}

