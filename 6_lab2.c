#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

void print_list(ListNode* head)
{
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL \n");
}

ListNode* concat_list(ListNode* head1, ListNode* head2)
{
    if (head1 == NULL) return head2;
    else if (head2 == NULL) return head1;
    else {
        ListNode* p;
        for (p = head1; p->link != NULL; p = p->link);
        p->link = head2;
        return head1;
    }
}

int main(void)
{
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;

    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    print_list(head1);

    head2 = insert_first(head2, 40);
    head2 = insert_first(head2, 50);
    head2 = insert_first(head2, 60);
    print_list(head2);

    print_list(concat_list(head1, head2));
    return 0;
}