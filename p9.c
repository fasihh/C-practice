#include <stdio.h>

void main() {
    int number, count;

    do {
        printf("Input number: ");
        scanf("%d", &number);

        if (number == 0) {
            printf("0 is not a prime number\n\n");
            main();
        };
    } while (number < 0);

    count = number / 2;

    while (number % count != 0) {
        count--;
    };

    (count == 1) ? printf("prime\n\n") : printf("not prime\n\n");

    main();
};