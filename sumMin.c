#include <stdio.h>
#include <stdlib.h>

long sum_two_smallest_numbers(size_t n, const int numbers[n]) {
  long total = 0;
  int *numl = malloc(n * sizeof(int));
  numl = numbers;
  
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j > 0 && numbers[j - 1] > numbers[j]) {
      int temp = numl[j];
      numl[j] = numl[j - 1];
      numl[j - 1] = temp;
      j--;
    }
  }
  
  return (long) numl[0] + numl[1];
}

int main() {
	return 0;
}