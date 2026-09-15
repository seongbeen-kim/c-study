
//재귀 코드(하노이)
/*
#include <stdio.h>

int count = 0;
int cost = 0;

// 하노이 변수명 파악 중요함
void hanoi(int n, char from, char tmp, char to)
{
    if(n==1)
    {
        printf("Disc %d: %c --> %c\n", n, from, to);
        count++;
        cost += n;
        return;
    }

    hanoi(n-1, from, to, tmp);
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
    printf("Total cost %d\n", cost);
    return 0;
}
*/

// 인접한 기둥으로만 옮길수 있는 하노이탑 문제

// n=2일 때는 8, 1번A->C, 2번A->B, 1번C->A, 2번B->C, 1번A->C, N-1개가 3번 분기된다.
// 3^n

/*
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
        cost += 2*n;
        return;
    }

    hanoi(n-1, from, tmp, to);
    printf("Disc %d: %c --> %c\n", n, from, tmp);
    hanoi(n-1, to, tmp, from);
    printf("Disc %d: %c --> %c\n", n, tmp, to);
    hanoi(n-1, from, tmp, to);
    count+=2;
    cost += 2*n;
}

int main(void)
{
    int n; 
    scanf("%d", &n);

    hanoi(n, 'A', 'B', 'C');

    printf("Total moves: %d\n", count);
    printf("Total cost: %d\n", cost);
    return 0;
}*/
/*
#include<stdio.h>

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("GCD: %d\n", gcd(a, b));
    return 0;
}*/

//피보나치 코드도 짜보자.
/*
int fibonacci(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("Fibonacci(%d): %d\n", n, fibonacci(n));
    return 0;
}*/ 

//피보나치 반복문 코드
