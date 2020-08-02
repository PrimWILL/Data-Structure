#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// === 스택 코드의 시작 ===
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType *s)
{
    s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType *s)
{
    return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입함수
void push(StackType *s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->data[++(s->top)] = item;
}

// 삭제함수
element pop(StackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

// 피크함수
element peek(StackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top];
}
// === 스택 코드의 끝 ===

void run_length(char in[])
{
    char ch, top_ch;
    int cnt = 0, len = strlen(in);
    StackType stack1;
    StackType stack2;
    init_stack(&stack1);
    init_stack(&stack2);
    for(int i = 0; i < len; i++) {
        ch = in[i];
        if (ch >= 'A' && ch <= 'Z') 
            push(&stack1, ch-'A'+'a');
        else 
            push(&stack1, ch);
    }
    ch = pop(&stack1);
    while(!is_empty(&stack1)) {
        top_ch = pop(&stack1);
        if (ch == top_ch) cnt++;
        else {
            push(&stack2, ch);
            push(&stack2, cnt+'0');
            cnt = 1;
            ch = top_ch;
        }
    }
    push(&stack2, ch);
    push(&stack2, cnt+'0');
    while(!is_empty(&stack2)) {
        printf("%c ", pop(&stack2));
    }
    printf("\n");
}

int main(void)
{
    char* s = "caaaAbBb";
    run_length(s);
    return 0;
}