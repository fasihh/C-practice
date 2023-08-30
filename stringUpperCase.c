#include <stdio.h>
#include <string.h>

char *makeUpperCase(char *);
char *makeUpperCaseEnhanced (char *);

void main() {
  char string[] = "afiahfijafiajf";
  printf("%s\n", makeUpperCaseEnhanced(string));
};

char *makeUpperCase (char *string)
{
  for (int i = 0; i < strlen(string); i++) {
    int charCode = (int) string[i];
    if (!(charCode <= 122 && charCode >= 97)) {
      continue;
    };

    string[i] = (char) ((int) string[i] - 32);
  };
  return string;
};

char *makeUpperCaseEnhanced (char *string)
{
  int i = 0;

  while(string[i]) {
    if (string[i] >= 'a' && string[i] <= 'z') {
      string[i] -= 32;
      i++;
    };
  };
  return string;
};