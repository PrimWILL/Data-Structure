#include <stdio.h>
#define ROWS 3
#define COLS 3

void add_matrix(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS]) {
    int array[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void matrix_print(int arr[ROWS][COLS]) {
    printf("===========================\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("===========================\n");
}

int main(void)
{
    int array1[ROWS][COLS] = { { 3,2,0 }, 
                               { 8,9,1 },
                               { 7,0,5 } };
    int array2[ROWS][COLS] = { { 6,2,5 }, 
                               { 3,6,2 },
                               { 7,0,5 } };
    int array3[ROWS][COLS] = { 0, };
    add_matrix(array1, array2, array3);
    matrix_print(array1);
    matrix_print(array2);
    matrix_print(array3);
    return 0;
}