
// 구조체 변수의 대입은 가능하지만 구조체 변수끼리의 비교는 불가능!!

/*
#include<stdio.h>

int main()
{
    typedef struct{
    int a;
    int b;
    
    } person;

    person A, B;
    A.a = 10;
    A.b = 20;

    B = A;
    printf("%d %d \n", A.a, A.b);
    printf("%d %d \n", B.a, B.b);

    if(A==B) // 구조체는 비교할 수 없다!!

    {
        printf("EQUAL\n");
    }

    else{
        printf("NOT EQUAL\n");
    }

    return 0;
}
*/

// 그럼에도 구조체 변수끼리 비교해보고 싶다면??

/*
#include<stdio.h>

int main()
{
    typedef struct{
    int a;
    int b;
    
    } person;

    person A, B;
    A.a = 10;
    A.b = 20;

    B = A;
    printf("%d %d \n", A.a, A.b);
    printf("%d %d \n", B.a, B.b);

    if(A.a == B.a && A.b == B.b) // 구조체 비교는 이런식으로 해야 한다!!

    {
        printf("EQUAL\n");
    }

    else{
        printf("NOT EQUAL\n");
    }

    return 0;
}
*/

// call by value 확인해보는 코드

/*
#include<stdio.h>

swap(int a, int b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a=1, b=2;

    printf("%d %d\n", a, b);
    swap(a,b); // call by value 값 만 던짐
    printf("%d %d\n", a, b);

    return 0;
}
*/

// call by reference 확인해보는 코드

/*
#include<stdio.h>

swap(int *a, int *b) // 함수에서도 주소값을 받는다.
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a=1, b=2;

    printf("%d %d\n", a, b);
    swap(&a, &b); // 포인터로 던지고 함수에서도 포인터로 받는다. call by reference
    printf("%d %d\n", a, b);

    return 0;
}*/



/*
#include<stdio.h>

int main()
{
     // typedef struct person{ 이런 식으로 작성하면 오류 발생
     // 온전히 c언어 기준으로는 잘못된 문법이나 vsc에서는 c++이 있어서 돌아감

    typedef struct{  
    int a;
    int b;
    } person;

    ////////////////////////////////////////////////////////////////
    typedef struct ListNode{   //C++에서는 이게 맞는 문법이다.!!
        int a;
        struct ListNode *LINK;
    } ListNode;

    // listnode  |a|*link| --> |a|*link|
    // ListNode = 데이터 + 다음 노드의 주소 


    // c언어 //
    ListNode A, B;
    A.a = 10;
    B.a = 20;
    A.LINK = &B; // A의 LINK에 B의 주소를 저장한다.
    B.LINK = NULL;

    ////////////////////////////////////////////////////////////////

    person A, B;
    A.a = 10;
    A.b = 20;

    B = A;
    printf("%d %d\n", A.a, A.b);
    printf("%d %d\n", B.a, B.b);

    if(A.a == B.a && A.b == B.b) // 구조체 비교는 이런식으로 해야 한다!!

    {
        printf("EQUAL\n");
    }

    else{
        printf("NOT EQUAL\n");
    }

    return 0;
}
*/

/*
int a;
int *p;
p = &a;

a    // 10
&a   // a의 주소 = 1000

p    // p 안에 저장된 값 = 1000 = a의 주소 (중요)
*p   // p가 가리키는 곳의 값 = 10 (중요)
&p   // p 자체의 주소 = 2000 (중요)
*/





