#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *morse[55] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."};  
const char *ascii[55] = {"A",  "B",    "C",    "D",   "E", "F",    "G",   "H",    "I",  "J",    "K",   "L",    "M",  "N",  "O",   "P",    "Q",    "R",   "S",   "T", "U",   "V",    "W",   "X",    "Y",    "Z",    "0",     "1",     "2",     "3",     "4",     "5",     "6",     "7",     "8",     "9",     ".",      ",",      "?",      "'",      "!",      "/",     "(",     ")",      "&",     ":",      ";",      "=",     "+",     "-",      "_",      "\"",     "$",       "@",      "SOS"};

char *decode_morse(const char* morse_code) {
  char *morse_code_cpy = strdup(morse_code), *text = (char *)calloc(strlen(morse_code), 1), *delim = " ";
  memset(text, ' ', strlen(morse_code));

  char *tPtr = text, *tok = strtok(morse_code_cpy, delim);

  while (tok) {
    for (int i = 0; i < 55; i++) {
      if (!strcmp(tok, morse[i])) {
        strcpy(tPtr, ascii[i]);
        tPtr += strlen(ascii[i]);
        break;
      }
    }

    if (*(tok + strlen(tok) + 1) == ' ') {
      *tPtr = *delim;
      tPtr += strlen(delim);
    }

    tok = strtok(0, delim);
  }

  *(tPtr) = '\0';

  return text;
}

char *encode_text(const char* text) {
  char *morse_code = (char *)malloc(sizeof("...---...") * strlen(text));
  char *morse_code_ptr = morse_code;
  memset(morse_code, ' ', strlen(morse_code));

  while (*text) {
    if (*text == ' ') {
      strcpy(morse_code_ptr, "  ");
      morse_code_ptr += strlen("  ");
      *text++;
      continue;
    }

    for (int i = 0; i < 55; i++) {
      if (*text == *ascii[i]) {
        char *str = strcat(strdup(morse[i]), " ");
        strcpy(morse_code_ptr, str);
        morse_code_ptr += strlen(str);
        break;
      }
    }

    *text++;
  }
  *(morse_code_ptr - 1) = '\0';

  return morse_code;
}

int main() {
  printf("%s\n", decode_morse(".... . .-.. .-.. ---   .-- --- .-. .-.. -.. -.-.--"));
  printf("%s\n", encode_text("HELLO WORLD!"));

  return 0;
}