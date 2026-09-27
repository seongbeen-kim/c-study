
// 희소행렬 입력받고 전치행렬을 출력하는 프로그램

#include <stdio.h>
#define MAX 100

int main(void)
{
    int A[MAX][MAX];
    int B[MAX][MAX];
    int rows, cols;

    scanf("%d %d", &rows, &cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &A[i][j]);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            B[j][i] = A[i][j];

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }

    return 0;
}