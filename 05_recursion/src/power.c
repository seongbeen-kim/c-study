
// 숫자 x의 n제곱값을 구하는 문제(x^n)

/*

// 재귀로 푸는 경우

#include<stdio.h>

int power(int x, int n)
{
    if(n==0)
    {
        return 1;
    }

    return x * power(x, n-1);
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
    for(int i=0; i<n; i++)
    {
        result = result * x;
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