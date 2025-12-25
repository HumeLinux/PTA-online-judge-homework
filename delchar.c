#include<stdio.h>

void delcharfun(char *str,char ch);
 
int main()
{
    char    ch,str[110];
    
    scanf("%s",str);    //读入字符串 
    getchar();            //读取回车符号 
    scanf("%c",&ch);    //读入字符 
    delcharfun(str,ch);    //删除 
    printf("%s\n",str);    //输出删除后结果 
    return 0;    
}

void delcharfun(char *str,char ch)
{
    char *p1,*p2;
    p1 = str;
    p2 = str;
    while(*p1 != '\0')
    {
        if(*p1 != ch)
        {
            *p2 = *p1;
            p2++;
        }
        p1++;
    }
    *p2 = '\0';
    return;
}