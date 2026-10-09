#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
} Node, *List;

// 删除递增链表中的重复元素
void DeleteRepeat(List head)
{
    Node *p = head->link;

    while (p != NULL && p->link != NULL)
    {
        if (p->data == p->link->data)
        {
            Node *q = p->link;
            p->link = q->link;
            free(q);
        }
        else
        {
            p = p->link;
        }
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
    int a[] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 70};
    int n = 10;

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

    printf("删除前：");
    PrintList(head);

    DeleteRepeat(head);

    printf("删除后：");
    PrintList(head);

    return 0;
}