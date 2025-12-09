#include <stdio.h>

int main()
{
    int n, m;
    int i, j;
    int matrix[11][11] = {0};
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int x, y, sum = 0;
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    scanf("%d %d", &x, &y);

    if(x < 1 || x > n || y < 1 || y > m)
    {
        printf("Invalid coordinates\n");
        return 0;
    }

    for(int k = 0; k < 8; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m)
        {
            sum += matrix[nx][ny];
        }
    }
    printf("%d\n", sum);
    return 0;
}