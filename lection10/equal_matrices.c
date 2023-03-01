#include <stdio.h>
#include <stdbool.h>

#define M 3
#define P 5
#define N 4

int matrix1[M][P] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
int matrix2[P][N] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20}};

void printMatrix(int matrix[M][N])
{
    for (int i = 0; i < M; i++)
    {
        if (i != 0)
        {
            printf("\n");   
        }

        for (int j = 0; j < N; j++)
        {
            printf("%2.d  ", matrix[i][j]);
        }
    }

    printf("\n\n");
}

void matrixMult(int dest_matrix[M][P], int src_matrix[P][N], int final_matrix[M][N])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            final_matrix[i][j] = 0;

            for (int k = 0; k < P; k++)
            {
                final_matrix[i][j] += dest_matrix[i][k] * src_matrix[k][j];
            }
        }
    }
}

int main(void)
{

    int final_matrix[M][N];

    matrixMult(matrix1, matrix2, final_matrix);

    printMatrix(final_matrix);

    return 0;
}