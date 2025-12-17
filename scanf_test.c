#include <stdio.h>

int main()
{
    /*char phone_number[12] = "";
    char name[20] = "";
    int num;

    num = scanf("09%[0-9-]", phone_number);
    if(num > 0)
        printf("You have entered: 09%s\n", phone_number);
    else
        printf("Input error.\n");
    
    num = scanf("%[^\n]", name);
    if(num > 0)
        printf("Hello, %s!\n", name);
    else
        printf("Input error.\n");
    return 0;*/
    char phone[11] = "";
    char msg_ok[] = "你输入的号码是 ";
    char msg_err[] = "手机号码要以 \"09\" 开头, 只能接受数字";
    char msg_prompt[] = "请输入 09 开头的手机号码：";

    int num;

    printf("%s", msg_prompt);
    num = scanf("09%[0-9-]", phone);
    if(num > 0)
        printf("%s09%s", msg_ok, phone);
    else
        printf("%s", msg_err);
}