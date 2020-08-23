#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct DListNode {
    element data;
    struct DListNode* rlink;
    struct DListNode* llink;
} DListNode;

DListNode* current;

void init(DListNode* phead)
{
    phead->rlink = phead;
    phead->llink = phead;
}

void print_dlist(DListNode* phead)
{
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        if (p == current)
            printf("<-| #%s# |-> ", p->data);
        else
            printf("<-| %s |-> ", p->data);
    }
    printf("\n");
}

void dinsert(DListNode* before, element data)
{
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    strcpy(newnode->data, data);
    newnode->rlink = before->rlink;
    newnode->llink = before;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed)
{
    if (removed == NULL) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

int main(void)
{
    char ch;
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);

    dinsert(head, "Gymnopedie");
    dinsert(head, "Disowned Memories");
    dinsert(head, "Butterflies");

    current = head->rlink;
    print_dlist(head);

    do {
        printf("\nPlease enter the instruction(<, >, q): ");
        ch = getchar();
        switch(ch) {
            case '<':   current = current->llink;
                        if (current == head)
                            current = current->llink;
                        break;
            case '>':   current = current->rlink;
                        if (current == head)
                            current = current->rlink;
                        break;   
        }
        print_dlist(head);
        getchar();
    } while (ch != 'q');

    free(head);
    free(current);
    return 0;
}