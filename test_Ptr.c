#include <stdio.h>


/*char* GetMem()
{
    char* p = "hello";
    return p;
}
int main()
{
    char *str = NULL;
    str = GetMem();
    printf("%s", str);
    return 0;
}*/
void GetMem(char** p)
{
    *p = "hello";
}
int main()
{
    char *str = NULL;
    GetMem(&str);
    printf("%s", str);
    return 0;
}