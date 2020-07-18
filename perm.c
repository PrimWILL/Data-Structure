#include <stdio.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void perm(char* list, int i, int n)
{
    int j, temp;
    if (i == n)
    {
        for (j = 0; j <= n; j++)
        {
            printf("%c", list[j]);
        }
        printf("\n");
    }
    else {
        /* list[i] to list[n] has more than one permutation,
        generate these recursively */
        for (j = i; j <= n; j++)
        {
            SWAP(list[i], list[j], temp);
            perm(list, i+1, n);
            SWAP(list[i], list[j], temp);
        }
    }
}

void main()
{
    char list[3] = {'a', 'b', 'c'};
    perm(list, 0, 3);
}