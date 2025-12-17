#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a[128] = {0};
    char ch;
    while((ch = getchar()) != '\n')
    {
        a[(int)ch]++;
    }
    for(int i = 65; i <= 90; i++)
    {
        if(a[i] != 0)
            printf("The character %c has presented %d times.\n", (char)i, a[i]);
    }
    for(int i = 97; i <= 122; i++)
    {
        if(a[i] != 0)
            printf("The character %c has presented %d times.\n", (char)i, a[i]);
    }
    return 0;
}