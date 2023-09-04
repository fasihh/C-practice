#include <stdio.h>

int factorial(int, int);

void main() {
    int number;

    do {
	printf("Input number > 0: ");
	scanf("%d", &number);	
    } while (number < 0);

    printf("Answer is %d\n\n", factorial(number, 1));

    main();
};

int factorial(int number, int answer) {
    if (number > 1) {
        answer *= number;
        number--;

        printf("answer = %d, number = %d\n", answer, number);
        return factorial(number, answer);
    } else {
        return answer;
    };
};
