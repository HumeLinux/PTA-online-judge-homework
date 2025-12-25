#include <stdio.h>

char *locatesubstr(char *str1,char *str2);
int main()
{
    char str1[505],str2[505];
    char *p;
    gets(str1);
    gets(str2);
    p=locatesubstr(str1,str2);
    
    if(p==NULL)    printf("NULL!\n");
    else    puts(p);
    
    return 0;
}

/* 请在这里填写答案 */
char *locatesubstr(char *str1,char *str2)
{
    char *p1,*p2,*p;
    p1 = str1;
    p2 = str2;
    while(*p1 != '\0')
    {
        p = p1;
        while(*p2 != '\0' && *p == *p2)
        {
            p++;
            p2++;
        }
        
        if(*p2 == '\0')
            return p1;
        else
        {
            p2 = str2;
            p1++;
        }
    }
    return NULL;
    
}