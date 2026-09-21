

//// 배열과 구조체 ////
// 만약 int, char이 있는 구조체라면 sizeof(struct) = 4byte(int) + 1byte(char) + 3byte(padding) = 8byte  
// 배열의 이름은 시작주소를 나타낸다.

// 배열에서 삽입, 삭제의 시간 복잡도는 O(n)이다. 
// 만약 맨 앞에 삽입하면 모든 요소가 한 칸씩 뒤로 이동해야 하므로 시간 복잡도는 O(n)이다.
// 만약 맨 뒤에 삽입하면 시간 복잡도는 O(1)이다.

// 2차원 배열도 1열로 나열되어 메모리에 저장된다.
// 2차원 배열에서 열의 정보가 중요하다(메모리 관점)

/*
최대차수 10이면 배열의 크기 11을 선언해야 한다.
처음 값을 다 0으로 세팅하고, 최대 차수가 5라면 5번 배열부터 입력을 받는다.
배열크기를 줄이면서 낮은 차수의 계수를 입력받으면 된다.
이러면 배열로 다항식을 표현할 수 있다.
*/

/*
// 다항식 코딩 예제

#include <stdio.h>
#define MAX 11

int main()
{
    int a, b, c;
    int A[MAX] = {0}; 
    int B[MAX] = {0};
    int C[MAX] = {0};

    scanf("%d", &a);
    for(int i=a; i>=0; i--)
        scanf("%d", &A[i]);
    scanf("%d", &b);
    for(int i=b; i>=0; i--)
        scanf("%d", &B[i]);

    c = (a>b)? a:b;

    for(int i=c; i>=0; i--)
        C[i] = A[i] + B[i];

    // 출력이 3x^4 +2x^3 + 5x^2 + 0x + 1이런식으로 출력이 되야 한다.
    
    for(int i=c; i>=0; i--)
    {
        if(i==1)
            printf("%dx", C[i]);
        if(i==0)
            printf("%d", C[i]);

        if(i==c)
            printf("%dx^%d", C[i], i);
        else
            printf(" +%dx^%d", C[i], i);
    }

    return 0;

}
*/

// 1차과제에서 9번 항목을 자세히 본다. 기왕이면 6개의 과제가 연결되는 편이 좋다 

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

/*
#include<stdio.h>

int main()
{
    typedef struct{   //typedef struct person{ 이런식으로 작성하면 오류 생김(온전히 c언어 기준으로는 잘못된 문법이다.), vsc에서는 c++이 있어서 돌아가긴해.
    int a;
    int b;
    
    } person;

    ////////////////////////////////////////////////////////////////
    typedef struct ListNode{   //C++에서는 이게 맞는 문법이다.!!
        int a;
        struct ListNode *LINK
    } ListNode;
    ////////////////////////////////////////////////////////////////

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
}*/

// listnode  |a|*link| --> |a|*link| (gpt)

// 임베디드 관점에서 동적할당은 필요하고, 그렇기 때문에 포인터를 사용해야 한다.
// 포인터에서 *p출력시 포인터가 가르키는 값이 출력 , p출력시 주소
// 포인터는 출력할 때 형식지정자는 %p 


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

    printf("%d %d\n", &a, &b);
    swap(a,b); // call by value 값 만 던짐
    printf("%d %d\n", &a, &b);

    return 0;
}*/

/*
#include<stdio.h>

swap(int *a, int *b) // 함수에서도 주소값을 받는다.
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a=1, b=2;

    printf("%d %d\n", &a, &b);
    swap(&a,&b); // 포인터로 던지고 함수에서도 포인터로 받는다, call by reference
    printf("%d %d\n", &a, &b);

    return 0;
}*/

// 지금까지 한 건 정적메모리

// 배열의 이름은 사실상의 포인터와 같은 역할로 첫 칸의 주소를 나타냄

// 동적배열








