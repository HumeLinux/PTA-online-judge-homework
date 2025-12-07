#include <stdio.h>

int main()
{
    int n,m;
    int matrix[100][100];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int j=0; j < m; j++)
    {
        for(int i=0; i < n-1; i++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("%d", matrix[n-1][j]);
        printf("\n");
    }
    return 0;
}