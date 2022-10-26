#include <stdio.h>

void print_matrix(int matrix[5][5])
{
    FILE *fp;
    int i, j;
    fp=fopen("matrix_out.txt", "a");
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            fprintf(fp," %d", matrix[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void input_matrix(int matrix[5][5])
{
    FILE *fp;
    fp=fopen("matrix_in.txt", "r");
    
    for(size_t i=0; i<5; i++)
    {
        for(size_t j=0; j<5; j++)
        {
             fscanf(fp, "%d", &matrix[i][j]);
        }
    }
    fclose(fp);
}

main()
{
    int (matrix)[5][5];
    input_matrix(matrix);

    print_matrix(matrix); 
    
}



