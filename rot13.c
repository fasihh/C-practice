#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rot13 (char *str_out, const char *str_in)
{
  int i = 0;
  char *result = (char *)malloc(sizeof(char) * 500);

  while (*str_in) {
    char ch;
    if (*str_in >= 'A' && *str_in <= 'Z') {
      ch = 'A';
    } else if (*str_in >= 'a' && *str_in <= 'z') {
      ch = 'a';
    } else {
      result[i++] = *str_in++;
      continue;
    }

    result[i++] = (*str_in++ - ch + 13) % 26 + ch;
  }
  result[i] = '\0';

  return result;
}

char *approachTwo(char *str_out, const char* str_in) {
	memset(str_out, '\0', strlen(str_out));

	return str_out;
}

int main() {
	char str_out[] = "EBG13 rknzcyr.";
	
	printf("%s\n", rot13(str_out, "EBG13 rknzcyr."));

	return 0;
}