#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define n 8

void init_desk(bool desk[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rand() % 2 == 0)
            {
                desk[i][j] = false;
                continue;
            }

            desk[i][j] = true;
        }
    }
}

void print_desk(bool desk[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", desk[i][j]);
        }

        printf("\n");
    }
}

bool horse_move(bool desk[n][n], int init_row, int init_col, int final_row, int final_col)
{
    if ((final_row == init_row + 1 || final_row == init_row - 1) && (final_col == init_col + 2 || final_col == init_col - 2) && desk[final_row][final_col] != true)
    {
        return true;
    }

    return false;
}


int main(void)
{
    bool desk[n][n];

    init_desk(desk);
    print_desk(desk);

    int init_row, init_col, final_row, final_col; 

    printf("Input starting row: ");
    scanf("%d", &init_row);
    printf("Input starting column: ");
    scanf("%d", &init_col);

    printf("Input final row: ");
    scanf("%d", &final_row);
    printf("Input final column: ");
    scanf("%d", &final_col);

    if (horse_move(desk, init_row, init_col, final_row, final_col))
    {
        printf("move is legal");
    }

    else if(horse_move(desk, init_row, init_col, final_row, final_col) == false)
    {
        printf("move is not legal");
    }

}