#include <stdio.h>
#include <math.h>


int gcd(int a, int b) {
    while (a != b) {
        (b > a) ? (b -= a) : (a -= b); 
    }

    return a;
}



void main() {
    int num1, num2, result;

    num1 = 25, num2 = 15;
    printf("Enter First Integer: ");
    //scanf("%d", &num1);
    printf("Enter Second Integer: ");
    //scanf("%d", &num2);
    result = gcd(num1, num2);
    printf("GCD of %d and %d is %d", num1, num2, result);
}