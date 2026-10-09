#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
} Node, *List;

// 将最小值结点移动到链表最前面
void MoveMin(List head)
{
    if (head->link == NULL ||
        head->link->link == NULL)
        return;

    Node *p = head->link;
    Node *pre = head;
    Node *min = p;
    Node *pre_min = head;

    while (p != NULL)
    {
        if (p->data < min->data)
        {
            min = p;
            pre_min = pre;
        }

        pre = p;
        p = p->link;
    }

    // 如果最小值结点不是第一个有效结点
    if (min != head->link)
    {
        pre_min->link = min->link;
        min->link = head->link;
        head->link = min;
    }
}

// 输出链表
void PrintList(List head)
{
    Node *p = head->link;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->link;
    }

    printf("\n");
}

int main()
{
    int a[] = {7, 10, 3, 21, 5};
    int n = 5;

    List head = (Node *)malloc(sizeof(Node));
    head->link = NULL;

    Node *r = head;

    for (int i = 0; i < n; i++)
    {
        Node *s = (Node *)malloc(sizeof(Node));
        s->data = a[i];
        s->link = NULL;

        r->link = s;
        r = s;
    }

    printf("移动前：");
    PrintList(head);

    MoveMin(head);

    printf("移动后：");
    PrintList(head);

    return 0;
}