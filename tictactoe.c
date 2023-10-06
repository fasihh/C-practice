#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
	return (turn & 1) ? 'o' : 'x';
}

void setValue(char* grid, int *pos, int turn) {
	char ch = getTurn(turn);
	*(grid + pos[0]*3 + pos[1]) = ch;
}

bool checkVertical(char *grid, char ch) {
	int c;
	for (int i = 0; i < 3; i++) {
		c = 0;

		for (int j = 0; j < 3; j++) {
			if (*(grid + j*3 + i) != ch) {
				break;
			}
			c++;
		}

		if (c == 3) return true;
	}
	

	return false;
}

bool checkHorizontal(char *grid, char ch) {
	int c;
	for (int i = 0; i < 3; i++) {
		c = 0;

		for (int j = 0; j < 3; j++) {
			if (*(grid + i*3 + j) != ch) {
				break;
			}
			c++;
		}

		if (c == 3) return true;
	}

	return false;
}

bool checkDiagonal(char *grid, int diag[3][2], char ch) {
	int c = 0;
	for (int i = 0; i < 3; i++) {
		if (*(grid + diag[i][0]*3 + diag[i][1]) != ch) {
			break;
		}

		c++;
	}

	return (c == 3) ? true : false;
}

bool checkStatus(char *grid, int turn) {
	int diag1[3][2] = {{0, 0}, {1, 1}, {2, 2}};
	int diag2[3][2] = {{2, 0}, {1, 1}, {0, 2}};
	char ch = getTurn(turn);

	return (checkVertical(grid, ch) || checkHorizontal(grid, ch) || checkDiagonal(grid, diag1, ch) || checkDiagonal(grid, diag2, ch) || turn >= 8) ? false : true;
} 

int main() {
	bool status = true;
	char posInput[2];
	int turn = 0;
	int *pos;
	char *grid = createGrid();
	displayGrid(grid);
	
	while (status) {
		printf("%d\n", turn);
		do {
			printf("\nEnter position '%c': ", getTurn(turn));
			gets(posInput);
			pos = getPos(posInput);

		} while (!checkPos(grid, pos));

		setValue(grid, pos, turn);
		displayGrid(grid);
		status = checkStatus(grid, turn);
		turn++;
	}

	if (turn >= 8) {
		printf("draw!");
	} else {
		printf("\n'%c' won!", getTurn(turn - 1));
	}
	
	getch();
	return 0;
}
