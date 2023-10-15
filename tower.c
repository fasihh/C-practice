#include <stdio.h>
#include <stdlib.h>

void alphabet_odd_pattern(int num, char ch) {
  if (!(num & 1)) {
    num -= 1;
  }

  char j = 'A';
  while (j <= ch) {

    int i = 1;
    while (i <= num) {
      printf("%c%d ", j, i);
      i += 2;
    }
    printf("\n");

    j++;
  }
}

void build_tower(int n, char tower[n][2 * n - 1])
{
  int floorSize = 2 * n - 1, stars = 1;
  
  int k = 0;
  while (n--) {
    
    int i = 0;
    while (i < n) {
      tower[k][i++] = ' ';
    }
    
    int j = stars;
    while (j--) {
      tower[k][i++] = '*';
    }
    
    while (i < floorSize) {
      tower[k][i++] = ' ';
    }

    stars += 2;
    k++;
  }
    
}

int main() {
  char tower[4][7] = {"       ", "       ", "       ", "       "};
  build_tower(4, tower);

  int n = 200, i = 0, j = 1;

  while (i < n) {
    if (!(i % 2)) {
      printf("%d ", j * 2);
    } else {
      printf("%d ", j * 5);
      j++;
    }

    if (i != n - 1) {
      if (i % 2) {
        printf("+ ");
      } else {
        printf("- ");
      }
    }

    i++;
  }

  return 0;
}