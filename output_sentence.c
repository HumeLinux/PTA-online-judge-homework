#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    char **sentences = (char **)malloc(n * sizeof(char *));
    for(int i = 0; i < n; i++)
    {
        sentences[i] = (char *)malloc(101 * sizeof(char));
        scanf(" %[^\n]", sentences[i]);
    }
}