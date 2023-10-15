#include <stdio.h>
#include <string.h>

void spin_words(const char *sentence, char *result) {
  int len = 0, i = 0, j = 0;

  while (sentence[i]) {
    result[i] = sentence[i]; len++;

    if (sentence[i + 1] == ' ' || sentence[i + 1] == '\0') {
      j = i - --len;

      if (len >= 4) {
        int k = i;
        while (j <= i) {
          result[j++] = sentence[k--];
        }
      }
      
      len = -1;
    }

    i++;
  }

  result[i] = '\0';
}

int main() {
  char result[200];
  spin_words("Welcome", result);

  printf("%s\n", result);
  return 0;
}