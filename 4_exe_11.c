#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 10

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

void expression(char ch[]) {
    StackType s;
    init_stack(&s);
    int i, len = strlen(ch), num = 1;
    for (i = 0; i < len; i++) {
        switch(ch[i]) {
            case '(': 
                printf("%d ", num);
                push(&s, num++);
                break;
            case ')': 
                printf("%d ", pop(&s));
                break;
        }
    }
    printf("\n");
}

int main(void)
{
    //char* s = "((())(()))";
    char* s = "(((((()";
    expression(s);
    return 0;
}