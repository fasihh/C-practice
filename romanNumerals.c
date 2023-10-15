#include <stdio.h>
#include <math.h>

unsigned decode_roman (const char *roman_number)
{
  int total = 0;
  
  while (*roman_number) {
    switch(*roman_number++) {
        case 'I':
          if (*roman_number == 'V') {
            total += 4;
            *roman_number++;
            break;
          } else if (*roman_number == 'X') {
            total += 9;
            *roman_number++;
            break;
          }
          total += 1;
          break;
        case 'V':
          if (*roman_number == 'I') {
            total += 6;
            *roman_number++;
            break;
          } 
          total += 5;   
          break;
        case 'X':
          if (*roman_number == 'C') {
            total += 90;
            *roman_number++;
            break;
          } else if (*roman_number == 'L') {
            total += 40;
            *roman_number++;
            break;
          }
          total += 10;
          break;
        case 'L':
          total += 50;
          break;
        case 'C':
          if (*roman_number == 'D') {
            total += 400;
            *roman_number++;
            break;
          } else if (*roman_number == 'M') {
            total += 900;
            *roman_number++;
            break;
          } 
          total += 100;
          break;
        case 'D':
          total += 500;
          break;
        case 'M':
          total += 1000;
          break;
    }
  }
	return total;
}

int main() {
  printf("%u\n", decode_roman("CDXII"));

  return 0;
}