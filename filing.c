#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeFile(char *, char *);
const char * readFile(char *);

int main() {

	writeFile("test.txt", "Hello World!\n\nTHIS WORKS!");

	const char *data = readFile("test.txt");
	printf("%s\n", data);

	free((void *)data);

	return 0;
}

void writeFile(char *fileName, char *line) {
	FILE *fptr;
	fptr = fopen(fileName, "w");

	fprintf(fptr, line);
	fclose(fptr);
}

const char * readFile(char *fileName) {
	FILE *fptr;
	char *fileData = NULL;
	int i = 0, n = 0;

	fileData = (char *)malloc(n * sizeof(char));
	fptr = fopen(fileName, "r");
	
	if (fileData == NULL) {
		fclose(fptr);
		return NULL;
	}

	while (!feof(fptr)) {
		char *new_fileData = (char *)realloc(fileData, n * sizeof(char));
		fileData = new_fileData;
		fileData[i] = fgetc(fptr);
		i++; n++;
	}
	fileData[i - 1] = '\0';

	fclose(fptr);

	return fileData;
}