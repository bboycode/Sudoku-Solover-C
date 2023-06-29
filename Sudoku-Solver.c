#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{	
	int ROWS = 9;
	int COLUMNS = 9;

	int board[COLUMNS][ROWS];

	FILE* file = fopen("test.txt", "r");
	
	if (file == NULL) {
		printf("File could not be used.\n");
		return 1;
	}
	
	int row = 0; 

	while (!feof(file)) {

		if (ferror(file)) {

			printf("Error reading file.\n");
			return 1;
		}
		
		for (int i =0; i < COLUMNS; i++) {

			if(fscanf(file, "%n" , &board[row][i]) == EOF){
				break;
			}
		
		}

		row ++; 
		
		if (row == ROWS) {
			break;
		}
	}

	fclose(file);

	for (int i = 0 ; i < ROWS; i++) {
		
		for (int j = 0; j < COLUMNS; j++) {

			printf("%d", board[i][j]);
		
		}

		printf("\n");

	}

	return 0;
}
