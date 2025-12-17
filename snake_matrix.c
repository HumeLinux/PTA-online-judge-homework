#include <stdio.h>

int main()
{
    int n;
    int i, j;
    int matrix[100][100];
    int num = 1;
    scanf("%d", &n);

    for(i = 0; i < 2*n-1; i++)
    {
        if(i % 2 != 0)
        {
            int row, col;   //row行 column列
            if(i <= n-1)
            {
                row = i;
                col = 0;
            }
            else
            {
                row = n - 1;
                col = i - (n - 1);
            }

            while(row >= 0 && col < n)
            {
                matrix[row][col] = num;
                num++;
                row--;
                col++;
            }
        }
        else
        {
            int row, col;
            if(i <= n-1)
            {
                row = 0;
                col = i;
            }
            else
            {
                row = i - (n - 1);
                col = n - 1;
            }

            while(row < n && col >= 0)
            {
                matrix[row][col] = num;
                num++;
                row++;
                col--;
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d", matrix[i][j]);
            if(j < n-1)
                printf(" ");
        }
            printf("\n");
    }
    return 0;
}