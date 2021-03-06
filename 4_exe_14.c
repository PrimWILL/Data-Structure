#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 6

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType* s) {
    s->top = -1;
}

int is_empty(StackType* s) {
    return (s->top == -1);
}

int is_full(StackType* s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
    if(is_full(s)) {
        fprintf(stderr, "Stack is full!\n");
        return;
    }
    else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
    if(is_empty(s)) {
        fprintf(stderr, "Stack is empty!\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(StackType* s) {
    if(is_empty(s)) {
        fprintf(stderr, "Stack is empty!\n");
        exit(1);
    }
    else return s->data[s->top];
}

int size(StackType* s) {
    return (s->top + 1);
}

int main(void) {
    StackType s;
    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);
    push(&s, 6);
    printf("%d %d \n", pop(&s), size(&s));
    printf("%d ", pop(&s));
    printf("%d ", pop(&s));
    printf("%d ", pop(&s));
    printf("%d ", pop(&s));
    printf("%d \n", pop(&s));
    return 0;
}