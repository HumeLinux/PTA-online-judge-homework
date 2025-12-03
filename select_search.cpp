#include<stdio.h>
using namespace std;
void selectSort(int data[],int elementCount) ;
int findMin(int data[], int startLoc, int endLoc) ;
void outputData(int data[],int elementCount) ;

int main()
{
    int        n , i,    num[1010] ;

    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ )
        scanf("%d",&num[i]) ;
    selectSort(num,n) ;
    return 0 ;
}
void selectSort(int data[],int elementCount)
{
    for (int i = 0; i< elementCount ; i++)
    {
        int minIndex = findMin(data , i , elementCount - 1);
        if (minIndex != i)
        {
            int temp = data[minIndex] ;
            data[minIndex] = data[i] ;
            data[i] = temp ;
        }
        outputData(data,elementCount) ;
    }

}
int findMin(int data[], int startLoc, int endLoc)
{
    int minIndex = startLoc ;
    int i;
    for( i = startLoc+1 ; i <= endLoc ; i++ )
    {
        if (data[i] < data[minIndex])
            minIndex = i;
    }
    return minIndex;
}

void outputData(int data[],int elementCount)
{
    int i;
    for( i = 0 ; i < elementCount-1 ; i++ )
        printf("%d ",data[i]) ;
    printf("%d\n",data[elementCount-1]) ;
}