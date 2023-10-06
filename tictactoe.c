#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

#define CH '.'

char *createGrid() {
	char *grid = (char *)calloc(9, sizeof(char));
	memset(grid, CH, 9);

	return grid;
}

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

bool checkPos(char *grid, int *pos) {
	return (pos[0] > 2 || pos[1] > 2 || pos[0] < 0 || pos[1] < 0 || (*(grid + pos[0]*3 + pos[1]) != CH)) ? false :  true; 
}

char getTurn(int turn) {
	return (turn & 1) ? 'x' : 'o';
}

void setValue(char* grid, int *pos, int turn) {
	*(grid + pos[0]*3 + pos[1]) = getTurn(turn);

}

// game logic remaining 
bool checkStatus(char *grid, int turn) {
	char ch = getTurn(turn);
	
	return true;
}

int main() {
	char posInput[2];
	int turn = 0;
	int *pos;
	char *grid = createGrid();
	displayGrid(grid);
	
	while (checkStatus(grid, turn)) {
		do {
			printf("Enter position: ");
			gets(posInput);
			pos = getPos(posInput);

		} while (!checkPos(grid, pos));

		setValue(grid, pos, turn);
		displayGrid(grid);
		turn++;
	}

	return 0;
}
