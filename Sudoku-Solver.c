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
            printf("---------------------\n");
        }
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
