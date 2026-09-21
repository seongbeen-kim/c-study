
// 하노이 탑(재귀 코드)

/*

// 원판 번호만큼 이동 비용이 드는 경우

#include <stdio.h>

int count = 0;
int cost = 0;

void hanoi(int n, char from, char tmp, char to) // 하노이 탑 문제는 변수명 파악 중요하다.
{
    if(n==1)
    {
        printf("Disc %d: %c --> %c\n", n, from, to);
        count++;
        cost += n;
        return;
    }

    hanoi(n-1, from, to, tmp); // from에서 tmp로 이동, to가 임시가 됨
    printf("Disc %d: %c --> %c\n", n, from, to);
    count++;
    cost += n;
    hanoi(n-1, tmp, from, to); // tmp를 to로 이동, from이 임시가 됨
}

int main(void)
{
    int n; 
    scanf("%d", &n);

    hanoi(n, 'A', 'B', 'C');

    printf("Total moves: %d\n", count);
    printf("Total cost: %d\n", cost);
    return 0;
}

*/


/*

// 인접한 기둥으로만 옮길수 있는 하노이탑 문제
// n=2일 때는 8, 1번A->B->C, 2번A->B, 1번C->B->A, 2번B->C, 1번A->B->C
// N-1개가 3번 분기된다.
hanoi(n-1, from, tmp, to);
hanoi(n-1, to, tmp, from);
hanoi(n-1, from, tmp, to);
즉 hanoi(n)을 한 번 실행하면 hanoi(n-1)을 3번 호출한다.
// O(3^n)

#include <stdio.h>

int count = 0;
int cost = 0;

void hanoi(int n, char from, char tmp, char to)
{
    if(n==1)
    {
        printf("Disc %d: %c --> %c\n", n, from, tmp);
        printf("Disc %d: %c --> %c\n", n, tmp, to);
        count+=2;
        cost+=2*n;
        return;
    }

    hanoi(n-1, from, tmp, to);
    printf("Disc %d: %c --> %c\n", n, from, tmp);
    hanoi(n-1, to, tmp, from);
    printf("Disc %d: %c --> %c\n", n, tmp, to);
    hanoi(n-1, from, tmp, to);
    count+=2;
    cost+=2*n;
    return;
}

int main(void)
{
    int n; 
    printf("n을 입력하세요: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'B', 'C');

    printf("Total moves: %d\n", count);
    printf("Total cost: %d\n", cost);
    return 0;
}

*/