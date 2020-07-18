/* �ǻ��ڵ�
void hanoi_tower(int n, char from, char tmp, char to)
{
    if(n==1)
    {
        from�� �ִ� �� ���� ������ to�� �ű��
    }
    else
    {
        from�� �� ���� ������ ������ ������ ���ǵ��� tmp�� �ű��
        from�� �ִ� �� ���� ������ to�� �ű��
        tmp�� ���ǵ��� to�� �ű��
    }
}
*/
/* �ǻ��ڵ�
void hanoi_tower(int n, char from, char tmp, char to)
{
    if(n==1)
    {
        from�� �ִ� �� ���� ������ to�� �ű��
    }
    else
    {
        hanoi_tower(n-1, from, to, tmp);
        from�� �ִ� �� ���� ������ to�� �ű��
        hanoi_tower(n-1, tmp, from, to);
    }
}
*/
#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to)
{
    if(n == 1)
    {
        printf("���� 1�� %c ���� %c���� �ű��.\n", from, to);
    }
    else
    {
        hanoi_tower(n - 1, from, to, tmp);
        printf("���� %d�� %c���� %c���� �ű��.\n", n, from, to);
        hanoi_tower(n - 1, tmp, from, to);
    }
}

int main(void)
{
    hanoi_tower(3, 'A', 'B', 'C');
    return 0;
}