#include <stdio.h>
#include <string.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y); // 起始点坐标
    
    char moves[9]; // 最长8个移动字符，加上结束符
    scanf("%s", moves);
    
    // 初始点对应的数字
    printf("%d", x * 3 + y + 1);
    
    int len = strlen(moves);
    for (int i = 0; i < len; i++) {
        char c = moves[i];
        // 根据移动方向更新坐标
        switch (c) {
            case '1': x += 1; y -= 1; break; // 左下
            case '2': x += 1; y += 0; break; // 下
            case '3': x += 1; y += 1; break; // 右下
            case '4': x += 0; y -= 1; break; // 左
            case '6': x += 0; y += 1; break; // 右
            case '7': x -= 1; y -= 1; break; // 左上
            case '8': x -= 1; y += 0; break; // 上
            case '9': x -= 1; y += 1; break; // 右上
        }
        // 输出新点对应的数字
        printf("%d", x * 3 + y + 1);
    }
    printf("\n");
    
    return 0;
}