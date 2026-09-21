
// 피보나치 수열

/*

// 0(2^n) 시간복잡도
// 재귀로 구현한 경우

#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;

    printf("n을 입력하세요: ");
    scanf("%d", &n);

    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));

    return 0;
}

*/

/*

// 반복문으로 구현한 경우

#include <stdio.h>

int fibonacci(int n)
{
    int a=0, b=1, c;
    if(n==0)
    {
        return 0;
    }

    for(int i = 2; i<=n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main()
{
    int n;

    printf("n을 입력하세요: ");
    scanf("%d", &n);

    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));

    return 0;
}

*/