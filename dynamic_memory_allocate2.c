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
            strPtr[]
        }
}
void fill(char ** strPtr , int n)
{
    
}