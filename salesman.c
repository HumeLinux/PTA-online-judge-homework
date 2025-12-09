#include <stdio.h>
#define MAX 100

int main()
{
    int n;
    int i,j;
    float matrix[5][4] = {0.0};
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        int salesman, product;
        float cash;
        scanf("%d %d %f", &salesman, &product, &cash);
        matrix[product - 1][salesman - 1]  += cash;
    }


    float rowSum[5] = {0.0};
    float colSum[4] = {0.0};
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 4; j++)
        {
            rowSum[i] += matrix[i][j];
        }
    }
    for(j = 0; j < 4; j++)
    {
        for(i = 0; i < 5; i++)
        {
            colSum[j] += matrix[i][j];
        }
    }
    float total = 0.0;
    for(i = 0; i < 5; i++)
    {
        total += rowSum[i];
    }
    

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%.1f\t", matrix[i][j]);
        }
        printf("%.1f\n", rowSum[i]);
    }

    for(j = 0; j < 4; j++)
    {
        printf("%.1f\t", colSum[j]);
    }
    printf("%.1f\n", total);
    return 0;
}