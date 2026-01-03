#include<stdio.h>
#include<stdlib.h>

char ** create1(int n) ;
void create2( char ** strPtr , int n ) ;
void fill(char ** strPtr , int n) ;


int main()
{
    int        n, i;
    char**    strPtr ;

    scanf("%d", &n );
    strPtr = create1( n * 2 + 1 ) ;
    create2( strPtr ,  n * 2 + 1 ) ;
    fill(strPtr , n) ;

    for (i = 0; i < 2 * n + 1; i++)
    {
        printf("%s\n" , strPtr[i]);
    }
    
    for ( i = 0 ; i < n * 2 + 1 ; i++ )
        free(strPtr[i]) ;
    free(strPtr) ;

    return 0;
}

char ** create1(int n)
{
    char ** strPtr;
    strPtr = (char **)malloc(n * sizeof(char *));
    return strPtr;
}
void create2( char ** strPtr , int n )
{
    for(int i = 0; i < n; i++)
        {
            strPtr[i] = (char *)malloc((n+1) * sizeof(char));
        }
}

void fill(char ** strPtr , int n)
{
    int rows = 2*n+1, cols = 2*n+1;
    int center = n;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            strPtr[i][j] = ' ';
        }
        strPtr[i][cols] = '\0';
    }

    for(int i = 0; i < rows; i++)
    {
        if(i == 0)
            strPtr[i][center] = 'X';
        else if(i < n)
        {
            int left = center - i;
            int right = center + i;
            strPtr[i][left] = '/';
            strPtr[i][right] = '\\';
        }
        else if(i == n)
        {
            strPtr[i][0] = 'X';
            strPtr[i][cols - 1] = 'X';
        }
        else if(i > n && i < rows - 1)
        {
            int left = center - (rows - 1 - i);  //倒三角
            int right = center + (rows - 1 - i);
            strPtr[i][left] = '\\';
            strPtr[i][right] = '/';
        }
        else if(i == rows - 1)
            strPtr[i][center] = 'X';
    }
}