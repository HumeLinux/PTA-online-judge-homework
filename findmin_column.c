#include<stdio.h>

#define        MAX        100

void findMin(int M[][MAX],int x[],int n,int m);

int main()
{
    int        matrix[MAX][MAX] ; 
    int        x[MAX] ;
    int        n, m, i, j ;


    scanf( "%d%d" , &n , &m );
    for( i = 0 ; i < n ; i++ )
    {    
        for( j = 0 ; j < m ; j++ )
        {
            scanf("%d", &matrix[i][j]) ;
        }
    }
    
    findMin(matrix,x,n,m);
    
    for( i = 0 ; i < m - 1 ; i++ )
        printf( "%d " , x[i] ) ;
    printf( "%d\n" , x[i] ) ;
    system("pause");
    return 0 ;
}

void findMin(int M[][MAX],int x[],int n,int m)
{
    int i, j;
    for(i = 0 ; i < m ; i++)
    {
        x[i] = M[0][i];
        for(j = 1; j< n; j++)
        {
            if(M[j][i] < x[i])
                x[i] = M[j][i]; 
        }
    }
}