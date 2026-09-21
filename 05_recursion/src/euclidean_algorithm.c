
// 유클리드 호제법

/*

// 재귀 코드

#include<stdio.h>

int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }

    return gcd(b, a%b);
}

int main()
{
    int a, b;

    printf("두 정수를 입력하세요: ");
    scanf("%d %d", &a, &b);

    printf("최대공약수 = %d\n", gcd(a, b));

    return 0;
}*/

// 반복문 코드

/*
#include<stdio.h>

int gcd(int a, int b)
{
    int r;
    
    while(b!=0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;

}

int main()
{
    int a, b;

    printf("두 정수를 입력하세요: ");
    scanf("%d %d", &a, &b);

    printf("최대공약수 = %d\n", gcd(a, b));

    return 0;
}*/