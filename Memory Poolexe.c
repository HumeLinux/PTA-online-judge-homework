#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);
    getchar(); // 吃掉换行符

    char *buffer = (char *)malloc(100005 * sizeof(char));
    char *strPtr[105];

    int current_pos = 0;
    for(i = 0; i < n; i++)
    {
        strPtr[i] = buffer + current_pos;

        gets(strPtr[i]);
        int len = strlen(strPtr[i]);
        current_pos += len + 1; // +1 for null terminator
    }

    char *temp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(strcmp(strPtr[j], strPtr[j + 1]) > 0)
            {
                temp = strPtr[j];
                strPtr[j] = strPtr[j + 1];
                strPtr[j + 1] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        puts(strPtr[i]);
    }
    free(buffer);
    return 0;
}