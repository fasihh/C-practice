#include <stdio.h>

void showNumbers(int, int);

void main() {
	showNumbers(2, 8);
}

void showNumbers(int start, int end) {
	if (start != end + 1) {
		printf("%d ", start);
		showNumbers(start + 1, end);
	}
	return;
}

