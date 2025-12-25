#include<stdio.h>
#include<stdlib.h>


int * create(int n) ;
void cal(int * array, int size) ;

int main()
{
    int * array , n , i ;
    
    scanf( "%d", &n );
    
    array = create(n) ;
    if ( array == NULL )
        return -1 ; //这里的return是因为没有获得内存而直接结束程序。
         
    cal( array, n) ;
    for ( i = 0 ; i < n ; i++ )
    {
        printf("%d" , *(array+i) ) ;
        if ( i == n - 1 ) printf("\n") ;
        else printf(" ") ;
    }     
    
    free(array) ;
    
    return 0;
}

int * create(int n)
{
    int * array;
    array = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    return array;
}
void cal(int * array, int size)
{
    double average;
    int sum = 0,maxn = -10000, minn = 10000;
    for(int i  = 0; i < size; i++)
    {
        sum += *(array+i);
        if(*(array+i) > maxn)
            maxn = *(array+i);
        if(*(array+i) < minn)
            minn = *(array+i);
    }
    average = sum*1.00/size;  //一开始这里搞错了，先乘1.00再除size

    printf("%d\n%.2lf\n%d\n%d\n",sum, average, maxn, minn);
}