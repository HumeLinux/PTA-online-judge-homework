#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j;
    if(scanf("%d", &n) != 1)
        return 1;
    getchar();

    char **strPtr = (char **)malloc(n * sizeof(char *));
    char buffer[1000];

    for(i = 0; i < n; i++)
    {
        if(fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            size_t len = strlen(buffer);
            if(len > 0 &&buffer[len - 1] == '\n')
            {
                buffer[len - 1] = '\0';
                len--;
            }
        }
        strPtr[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        if(strPtr[i] != NULL)
        {
            strcpy(strPtr[i], buffer);
        }
    }

    char *temp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i -1; j++)
        {
            if(strcmp(strPtr[j],strPtr[j + 1]) > 0)
            {
                temp = strPtr[j];
                strPtr[j] = strPtr[j + 1];
                strPtr[j + 1] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        printf("%s\n", strPtr[i]);
    }
    for(i = 0; i < n; i++)
    {
        free(strPtr[i]);
    }
    free(strPtr);
    return 0;
}