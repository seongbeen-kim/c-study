
// 다항식 코딩 예제

#include <stdio.h>
#define MAX 100

int main(void)
{
    int A[MAX] = {0};
    int B[MAX] = {0};
    int C[MAX] = {0};
    int degreeA, degreeB, maxDegree;

    scanf("%d", &degreeA); // A차수 입력
    for (int i = degreeA; i >= 0; i--)
        scanf("%d", &A[i]); // 다항식 A 입력

    scanf("%d", &degreeB); // B차수 입력
    for (int i = degreeB; i >= 0; i--)
        scanf("%d", &B[i]); // 다항식 B 입력

    maxDegree = (degreeA > degreeB) ? degreeA : degreeB; // A랑 B중 큰 차수 파악

    for (int i = 0; i <= maxDegree; i++)
        C[i] = A[i] + B[i]; // // A랑 B를 더함

    for (int i = maxDegree; i >= 0; i--)
    {
        if (C[i] == 0) // 0일 때 처리
            continue; // continue를 만나면 현재 반복에서 continue 아래에 있는 코드를 전부 건너뛰고, 바로 다음 반복으로 넘어간다.

        if (i != maxDegree) // 최고차항이 아닌 경우
            printf(" + ");

        if (i == 0) // 1차 일 때
            printf("%d", C[i]);
        else if (i == 1) // 상수 일 때
            printf("%dx", C[i]);
        else // 그 외의 경우
            printf("%dx^%d", C[i], i);
    }

    return 0;
}
