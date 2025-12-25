
#include<stdio.h>

#define        MAXLEN        110

int        isPrime( int n ) //判断一个整数是否是质数，是则返回1，否则返回0 
{
    if( n < 2 ) return 0 ;
    for( int i = 2 ; i*i <= n ; i++ )
        if( n % i == 0 ) return 0 ;
    return 1 ;
}
int        getResult( char word[] )
{
    int max = -1, min = 1000;
    int ascii[128] = {0} ;

    for( int i = 0 ; word[i] != '\0' ; i++ )
    {
        int val = (int)( word[i] ) ;
        ascii[val]++ ;
    }

    for( int i = 0; i < 128; i++)
    {
        if(max < ascii[i])
            max = ascii[i];
        if(min > ascii[i] && ascii[i] != 0)
            min = ascii[i];
    }
    if( isPrime( max - min ) )
        return max - min;
    else
        return -1 ;
}

int main()
{
    char    word[MAXLEN] ;

    scanf( "%s" , word ) ;            
    printf( "%d\n" , getResult( word ) );

    return 0;
}
