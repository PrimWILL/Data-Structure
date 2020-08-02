#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 10

typedef char element;

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

void remove_num(char in[])
{
    char ch = in[0];
    int len = strlen(in);
    StackType stack, stack2;
    init_stack(&stack);
    init_stack(&stack2);
    push(&stack, ch);
    for (int i = 1; i < len; i++) {
        ch = in[i];
        if (ch != peek(&stack)) push(&stack, ch);
    }
    while(!is_empty(&stack)) push(&stack2, pop(&stack));
    while(!is_empty(&stack2)) printf("%c ", pop(&stack2));
    printf("\n");
}

int main(void) {
    char s[10];
    printf("정수를 입력하시오: ");
    scanf("%s", s);
    remove_num(s);
    return 0;
}