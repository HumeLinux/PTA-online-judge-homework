#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *row;
    long long sum;
    int index;
} RowData;

int compare(const void *a, const void *b)
{
    RowData *rowA = (RowData *)a;
    RowData *rowB = (RowData *)b;
    
    if(rowA->sum < rowB->sum)
        return -1;
    if(rowA->sum > rowB->sum)
        return 1;
    
    return rowA->index - rowB->index;
}

int main()
{
    int n;
    scanf("%d", &n);

    int **matrix = (int **)malloc(n * sizeof(int *));
    RowData *rows = (RowData *)malloc(n * sizeof(RowData));

    for(int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
        rows[i].row = matrix[i];
        rows[i].sum = 0;
        rows[i].index = i;

        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
            rows[i].sum += matrix[i][j];
        }
    }

    qsort(rows, n, sizeof(RowData), compare);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d", rows[i].row[j]);
            if(j < n-1)
                printf(" ");
            else
                printf("\n"); 
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    return 0;
}