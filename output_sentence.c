#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d\n", &n);

    char **str = (char **)malloc(n * sizeof(char *));
    for(int i = 0; i < n; i++)
    {
        str[i] = (char *)malloc(31 * sizeof(char));
        scanf("%s", str[i]);
    }

    int *order = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &order[i]);
    }

    for(int i = 0; i < n; i++)
    {
        printf("%s\n", str[order[i]]);
    }

    for(int i = 0; i < n; i++)
    {
        free(str[i]);
    }
    free(str);
    free(order);
    return 0;
}