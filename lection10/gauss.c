#include <stdio.h>

#define rows 3
#define cols 4

void eliminate(float matrix[rows][cols])
{
    for (int j = 0; j < cols - 2; j++)
    {
        for (int i = rows; i > 0; i--)
        {
            float factor = matrix[i][j] / matrix[0][0];
        }
    }
}

void row_sum(float matrix[rows][cols], int row_number1, int row_number2, float factor)
{
    for (int i = 0; i < cols; i++)
    {
        matrix[row_number1][i] -= matrix[row_number2][i]*factor;
    }
}

void print_matrix(float matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%5.1f ", matrix[i][j]);
        }

        printf("\n");
    }
}

int main(void)
{
    float matrix[rows][cols] = {{1, 1, -1, -2}, {2, -1, 1, 5}, {4, 2, 2, 1}};

    print_matrix(matrix);

    printf("\n\n");

    float factor = matrix[2][0] / matrix[0][0];

    row_sum(matrix, 2, 0, factor);

    //eliminate(matrix);

    print_matrix(matrix);
}