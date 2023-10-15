#include <stdio.h>

void hanoi(int disks, char src, char dest, char temp) {
    if (disks > 0) {
        hanoi(disks - 1, src, temp, dest);
        printf("move disc from %c to %c\n", src, dest);
        hanoi(disks - 1, temp, dest, src);
    }
}

int main() {
    hanoi(3, 'A', 'C', 'B');
}