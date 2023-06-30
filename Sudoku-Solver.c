#include <stdio.h>
#include <stdlib.h>

#define ROWS 9
#define COLUMNS 9

void printSudokuBoard(int board[ROWS][COLUMNS])
{
    for (int row = 0; row < ROWS; row++)
    {

        for (int col = 0; col < COLUMNS; col++)
        {

            printf("%d", board[row][col]);

                if (((col + 1) % 3 == 0 && col != COLUMNS - 1))
            {
                printf("| ");
            }
        }
        printf("\n");

        if ((row + 1) % 3 == 0 && row != ROWS - 1)
        {
            printf("--------------\n");
        }
    }
}

int checkRow(int Board[ROWS][COLUMNS], int row, int col, int num){
    
    for (int i = 0; i < 9; i++) {

        if(num == Board[row][i] && i != col){
            
            return 1;
        }
    
    }

    return 0;
}

int checkColumn(int Board[ROWS][COLUMNS], int row, int col, int num){

    for (int i = 0; i< 9; i++) {
        
        if(num == Board[i][col] && i != row){

            return 1;
        }
    }

    return 0;
}

int checkBox(int Board[ROWS][COLUMNS], int row, int col, int num){

    int startRow = (row/3) * 3;
    int startCol = (col/3) * 3; 

    for (int i = startRow; i < startRow +3; i++) {
        
        for (int j = startCol; j < startCol +3; j++) {
            
            if(num == Board[i][j] && i != row && j != col ){

                return 1; 

            }
            
        }
    }

    return 0;
}

int isValid(int Board[ROWS][COLUMNS], int row, int col, int num){
    

    if(checkRow(Board, row, col, num) == 1 || checkColumn(Board, row, col, num) == 1 || checkBox(Board, row, col, num)){

        return 1;
    }

    return 0;
}

void solve(int Board[ROWS][COLUMNS]){
    
   int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int nums = 0;nums ; inc-expression) {
    
    }

    
}

int main(int argc, char *argv[])
{

    int board[ROWS][COLUMNS];

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("File could not be opened.\n");
        return 1;
    }

    int row = 0;
    int column = 0;

    // Reads from text file.
    while (row < ROWS && !feof(file))
    {
        if (ferror(file))
        {
            printf("Error reading file.\n");
            return 1;
        }

        if (fscanf(file, "%1d", &board[row][column]) == EOF)
        {
            break;
        }

        column++;
        if (column == COLUMNS)
        {
            column = 0;
            row++;
        }
    }

    fclose(file);

    printSudokuBoard(board);

    return 0;
}
