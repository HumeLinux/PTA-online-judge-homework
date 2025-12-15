#include <stdio.h>

int main()
{
    int n, m;
    int i, j;


    int **matrix;
    scanf("%d %d", &n, &m);
    matrix = (int **)malloc((n + 1) * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc((m + 1) * sizeof(int));
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);  // n row m column
        }
    }

    int x, y, value;
    int saddle_point_found = 0;
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            int is_saddle_point = 1;
            int current_value = matrix[i][j];

            for(int k = 0; k < m; k++)
            {
                if(matrix[i][k] > current_value)
                {
                    is_saddle_point = 0;
                    break;
                }
            }

            if(!is_saddle_point)
                continue;

            for(int k = 0; k < n; k++)
            {
                if(matrix[k][j] < current_value)
                {
                    is_saddle_point = 0;
                    break;
                }
            }
            if(is_saddle_point)
            {
                saddle_point_found = 1;
                x = i;
                y = j;
                value = current_value;
                break;
            }
        }
        if(saddle_point_found)
            break;
    }
    if (saddle_point_found)
    {
        printf("The saddle point is (%d,%d)=%d.\n", x, y, value);
    }
    else
    {
        printf("There is no saddle point in the matrix.\n");
    }
    return 0;
}