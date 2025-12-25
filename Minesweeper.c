#include <stdio.h>
#include <stdlib.h>

int main()
{
    int grid[9][9] = {0};
    int t;
    int i, j;
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    scanf("%d", &t);

    while(t--)
    {
        int r, c;
        scanf("%d %d", &r, &c);
        int x, y;
        x = r - 1;
        y = c - 1;

        int mine_count = 0;

        for(int dx = x-1; dx <= x+1; dx++)
        {
            for(int dy = y-1; dy <= y+1; dy++)
            {
                if(dx >= 0 && dx < 9 && dy >= 0 && dy < 9)
                {
                    if( dx == x && dy == y)
                        continue;
                    if(grid[dx][dy] == 1)
                        mine_count++;
                }  
            }
        }
        printf("%d\n", mine_count);
    }
}