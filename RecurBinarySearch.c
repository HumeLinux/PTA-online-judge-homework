#include<stdio.h>
#include<stdlib.h>

#define MAXN 2000

int RecurBinarySearch(int a[], int key, int left, int right);

int main()
{
    int *a = (int *)malloc(MAXN * sizeof(int)); // 使用堆内存
    if (a == NULL) {
        printf("内存分配失败\n");
        return -1;
    }
    
    int n, m, i, key;
    
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
        
    for (i = 0; i < m; i++)
    {
        scanf("%d", &key);
        printf("%d", RecurBinarySearch(a, key, 0, n - 1));
        if (i != m - 1) printf(" ");
        else printf("\n");
    }
    
    free(a); // 释放内存
    return 0;
}

int RecurBinarySearch(int a[], int key, int left, int right)
{
    if (left > right)
    {
        return -1;  // 修正：去掉一个分号
    }
    int mid = left + (right - left) / 2;
    
    if (a[mid] == key)
    {
        return mid;
    }
    else if (a[mid] < key)
    {
        return RecurBinarySearch(a, key, mid + 1, right);
    }
    else
    {
        return RecurBinarySearch(a, key, left, mid - 1);
    }
    return -1; // 这一行实际上不会被执行到，可以省略
}