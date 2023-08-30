#include <stdio.h>

int getFare(int, int, int);

void main() {
  char gender;
  int distance;
  int age;
  int fare; 
  char userInput;

  do {
    printf("Input age, gender and distance to travel: ");
    scanf("%d %c %d", &age, &gender, &distance);
  } 
  while (gender != 'm' && gender != 'f' || age <= 0 || distance <= 0);

  if ((gender == 'm' && age >= 18) || (gender == 'f' && age >= 16)) {
    fare = getFare(distance, 5, 10);
  } else {
    fare = getFare(distance, 3, 5);
  };

  printf("Total fare is %d", fare);

  printf("\n\n");
  main();
};

int getFare(int distance, int rate, int baseFare) {
  if (distance > 5) {
    return (((distance - 5) * rate)) + baseFare;
  };
  return baseFare;
};
