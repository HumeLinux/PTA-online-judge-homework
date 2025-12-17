#include <stdio.h>
#include <stdlib.h>

void sort_array(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    sort_array(arr, n);
    if(n % 2 ==0)
    {
        for(int i = (n/2); i < n; i++)
        {
            if(arr[i] % 2 == 0)
                sum += (arr[i]/2);
            else
                sum += (arr[i]-1)/2;
        }
        printf("%d\n", sum);
    }
    else
    {
        for(int i = (n-(n-1)/2); i < n; i++)
        {
            if(arr[i] % 2 == 0)
                sum += (arr[i]/2);
            else
                sum += (arr[i]-1)/2;
        }
        printf("%d\n", sum);
    }
    return 0;
}