
// 빠르게 숫자 x의 n제곱값을 구하는 문제(x^n)
// 시간 복잡도 o(logn)

/*

// 재귀로 푸는 경우

#include<stdio.h>

int power(int x, int n)
{
    if(n==0)
    {
        return 1;
    }

    if(n%2==0)
    {
        return power(x*x, n/2);
    }

    else
    {
        return x*power(x*x, (n-1)/2);
    }
}

int main()
{
    int x, n;

    printf("x와 n을 입력하세요: ");
    scanf("%d %d", &x, &n);

    printf("%d^%d = %d\n", x, n, power(x,n));

    return 0;
}

*/

/*

// 반복문으로 푸는 경우

#include<stdio.h>

int power(int x, int n)
{
    int result = 1;
    for(;n>0;n/=2)
    {
        if(n%2==1)
        {
            result*=x;
        }
        x*=x;
    }

    return result;
}

int main()
{
    int x, n;

    printf("x와 n을 입력하세요: ");
    scanf("%d %d", &x, &n);

    printf("%d^%d = %d\n", x, n, power(x,n));

    return 0;
}

*/