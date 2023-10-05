#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define CH '.'

void displayGrid(char *grid) {
	printf("  ");
	for (int k = 0; k < 3; k++) {
		printf("%d ", k + 1);
	}
	printf("\n");
	for (int i = 0; i < 3; i++) {
		printf("%c ", i + 'a');
		for (int j = 0; j < 3; j++) {
			printf("%c ", *(grid + i*3 + j));
		}
		printf("\n");
	}
}

char *createGrid() {
	char *grid = (char *)calloc(9, sizeof(char));
	memset(grid, CH, 9);

	return grid;
}

int *getPos(char *pos) {
	int x, y;

	if (*pos >= 97) {
		x = (int) *pos++ - 97;
		y = (int) *pos - 49;
	} else {
		y = (int) *pos++ - 49;
		x = (int) *pos - 97;
	}

	return (int[2]){x, y};
}

int checkPos(char *grid, int *pos) {
	return (pos[0] > 2 || pos[1] > 2 || pos[0] < 0 || pos[1] < 0 || (*(grid + pos[0]*3 + pos[1]) != CH)) ? false :  true; 
}

void setValue(char* grid, int *pos, int turn) {
	char ch;
	if (turn & 1) 
		ch = 'x';
	else
		ch = 'o';

	*(grid + pos[0]*3 + pos[1]) = ch;

}

int main() {
	char  *grid = createGrid();
	
	displayGrid(grid);
	
	return 0;
}
