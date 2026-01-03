#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct Node {
    int id;
    struct Node *next;
} Node;

void solveJosephusLink(int n, int k) {
    if (n < 1 || k < 1) return;

    // 1. 创建循环链表
    Node *head = (Node *)malloc(sizeof(Node));
    head->id = 1;
    Node *prev = head;
    for (int i = 2; i <= n; i++) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->id = i;
        prev->next = newNode;
        prev = newNode;
    }
    prev->next = head; // 首尾相连形成环

    // 2. 开始报数出局
    Node *curr = head;
    Node *before = prev; // 始终指向当前节点的前一个，方便删除

    printf("出局顺序: ");
    while (curr->next != curr) { // 只要圈里不止一个人
        // 报数：移动 k-1 次到达第 k 个人
        for (int count = 1; count < k; count++) {
            before = curr;
            curr = curr->next;
        }
        // 删除当前节点 curr
        printf("%d ", curr->id);
        before->next = curr->next;
        Node *temp = curr;
        curr = curr->next; // 从下一个人开始重新报数
        free(temp);
    }

    printf("\n最后幸存者: %d\n", curr->id);
    free(curr); // 释放最后一个节点
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    solveJosephusLink(n, k);
    return 0;
}