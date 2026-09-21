
// 팩토리얼

/*

// 재귀 코드

#include<stdio.h>

int factorial(int n)
{
    if(n==0)
    {
        return 1;
    }

    return n*factorial(n-1);

}

int main()
{
    int n; 

    printf("정수를 입력하세요: ");
    scanf("%d", &n);

    printf("%d! = %d\n", n , factorial(n));

    return 0;
}
*/

/*

// 반복문 코드

#include<stdio.h>

int factorial(int n)
{
    int result = 1;
    for(int i=1; i<=n; i++)
    {
        result = result * i;
    }

    return result;

}

int main()
{
    int n; 

    printf("정수를 입력하세요: ");
    scanf("%d", &n);

    printf("%d! = %d\n", n , factorial(n));

    return 0;
}
*/

