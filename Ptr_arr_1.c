#include<stdio.h>

int getString( char * source , char *strPtr[] ) ;

int main()
{
    char    str[100005];
    char    *strPtr[1005]={0};
    int        i, num ;
    
    gets(str);
    num = getString( str , strPtr ) ;
    for( i = 0 ; i < num ; i++ )
        puts(strPtr[i]);
    
    return 0;    
}

/* 请在这里填写答案 */
int getString( char * source , char *strPtr[] )
{
    int count = 0;
    int inword  = 0;
    int i = 0;

    while(source[i] != '\0')
    {
        if(source[i] == ' ')
        {
            if(inword)
            {
                source[i] = '\0';
                inword = 0;
            }
        }
        else
        {
            if(!inword)
            {
                strPtr[count++] = &source[i];
                inword = 1;
            }
        }
        i++;
    }
    return count;
}