#include <stdio.h>

#define R 5
#define C 20

int matrix1[R][C];
int square_matrix[R][R] = {{1, 2, 3, 4, 5}, {2, 4, 6, 8, 10}, {3, 6, 9, 12, 15}, {4, 8, 12, 16, 20}, {5, 10, 15, 20, 25}};

void printDiagonal(int matrix[R][R])
{
    printf("\n");

    for (int i = 0; i < R; i++)
    {
        printf("matrix[%d][%d] = %d\n", i,i, matrix[i][i]);
    }
}

void printSecondDiagonal(int matrix[R][R])
{
    printf("\n");
    for (int i = 0; i < R; i++)
    {
        printf("matrix[%d][%d] = %d\n", i,R-i-1, matrix[i][R-i-1]);
    }
}

void printMatrix(int matrix[R][R])
{
    for (int i = 0; i < R; i++)
    {
        if (i != 0)
        {
            printf("\n");   
        }

        for (int j = 0; j < R; j++)
        {
            printf("%2.d  ", matrix[i][j]);
        }
    }

    printf("\n\n");
}

int main(void)
{
    printMatrix(square_matrix);
    printDiagonal(square_matrix);
    printSecondDiagonal(square_matrix);
}