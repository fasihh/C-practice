#include <stdio.h>

void main() {
	float speed;

	printf("Input speed in miles per hour: ");
	scanf("%f", &speed);

	speed = (float) (speed * 1.6) / 3600;

	printf("Speed in kilometers per second: %.2f", speed);
};
