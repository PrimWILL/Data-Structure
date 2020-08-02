#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 20

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

void big2little(StackType* s1, StackType* s2, char in[]) {
    int len = strlen(in);
    init_stack(s1);
    init_stack(s2);
    for (int i = 0; i < len; i++) {
        if (in[i] >= 'A' && in[i] <= 'Z'){
            push(s1, in[i]-'A'+'a');
            push(s2, in[i]-'A'+'a');
        }
        else if (in[i] >= 'a' && in[i] <= 'z') {
            push(s1, in[i]);
            push(s2, in[i]);
        }
    }
}

int main(void) {
    char ch[20];
    printf("Please enter the string: ");
    scanf("%[^\n]s", ch);

    StackType stack1, stack2, stack3;
    big2little(&stack1, &stack2, ch);
    
    init_stack(&stack3);
    while(!is_empty(&stack1)) {
        push(&stack3, pop(&stack1));
    }
    while(!is_empty(&stack3)) {
        //printf("%c %c\n", peek(&stack3), peek(&stack2));
        if (pop(&stack3) != pop(&stack2)) {
            printf("It's not a palindrome.\n");
            return;
        }
    }
    printf("It's palindrome\n");
    return 0;
}