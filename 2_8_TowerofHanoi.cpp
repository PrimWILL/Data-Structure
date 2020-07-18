/* 의사코드
void hanoi_tower(int n, char from, char tmp, char to)
{
    if(n==1)
    {
        from에 있는 한 개의 원판을 to로 옮긴다
    }
    else
    {
        from의 맨 밑의 원판을 제외한 나머지 원판들을 tmp로 옮긴다
        from에 있는 한 개의 원판을 to로 옮긴다
        tmp의 원판들을 to로 옮긴다
    }
}
*/
/* 의사코드
void hanoi_tower(int n, char from, char tmp, char to)
{
    if(n==1)
    {
        from에 있는 한 개의 원판을 to로 옮긴다
    }
    else
    {
        hanoi_tower(n-1, from, to, tmp);
        from에 있는 한 개의 원판을 to로 옮긴다
        hanoi_tower(n-1, tmp, from, to);
    }
}
*/
#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to)
{
    if(n == 1)
    {
        printf("원판 1을 %c 에서 %c으로 옮긴다.\n", from, to);
    }
    else
    {
        hanoi_tower(n - 1, from, to, tmp);
        printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, from, to);
        hanoi_tower(n - 1, tmp, from, to);
    }
}

int main(void)
{
    hanoi_tower(3, 'A', 'B', 'C');
    return 0;
}