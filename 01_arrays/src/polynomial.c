
// 다항식 코딩 예제

// 최대차수 10이면 배열의 크기 11을 선언해야 한다.
// 처음 값을 다 0으로 세팅하고, 최대 차수가 5라면 5번 배열부터 입력을 받는다.
// 배열크기를 줄이면서 낮은 차수의 계수를 입력받으면 된다.
// 이러면 배열로 다항식을 표현할 수 있다.


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
