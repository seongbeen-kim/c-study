
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

/*
int fibonacci_iterative(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;

    int a = 0, b = 1, c;
    for(int i=2; i<=n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
*/

//// 미로출구 ////

// 초급문제는 피보나치, 최대공약수 정도
// 중간고사 중급 문제로 나옴. (2~3)
// 킬러 1개

//지나온 곳에 대한 표시가 필요하다. 
//처음 배열에 0으로 초기화하고 지나온 곳은 1로 표시한다.
// 팀 프로젝트에서는 지역변수 사용, 혼자는 전역변수 사용 가능
// 대각선으로 이동이 가능한다면 움직임에 대한 조건이 4개 더 추가된다.

/*
#include<stdio.h>
#define MAX 20

int n, m;
int maze[MAX][MAX];
int visited[MAX][MAX]; // 지나온 곳 표시하기 위함

int findExit(int x, int y)
{
    if(x<0 || x>=n || y<0 || y>=m) // 범위 벗어나면 false
        return 0;
    if(maze[x][y]==1 || visited[x][y]==1) // 벽이거나 이미 지나온 곳이면 false
        return 0;
    if(x==n-1 && y==m-1) // 출구에 도착하면 true
        return 1;

    visited[x][y] = 1; // 지나온 곳 표시
    if(findExit(x-1,y)) return 1;
    if(findExit(x+1,y)) return 1;
    if(findExit(x,y-1)) return 1;
    if(findExit(x,y+1)) return 1;

    ////////// 대각선으로 이동이 되는 경우//////////

    // 상하좌우 이동하는경우
    if(findExit(x-1,y)) return 1;
    if(findExit(x+1,y)) return 1;
    if(findExit(x,y-1)) return 1;
    if(findExit(x,y+1)) return 1;


    /*
    // 대각선 이동하는 경우
    if(findExit(x-1,y-1)) return 1;
    if(findExit(x-1,y+1)) return 1;
    if(findExit(x+1,y-1)) return 1;
    if(findExit(x+1,y+1)) return 1;
    */
    // 위와 같이 if구문 8번을 돌려도 되지만 배열+반복문을 사용해도 된다.

    /*
    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}; 
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1}; 
    for(int i=0; i<8; i++)
    {
        if(findExit(x+dx[i], y+dy[i]))
            return 1;
    }   
    */
/*
    return 0;

    // 재귀는 반드시 종료조건이 있어야 한다. 
    // 재귀는 반드시 문자값이 줄어들어야 한다.
    // 문자값이 늘어난다면 그에 대한 종료조건이 필요하다


}
*/
/*
#include<stdio.h>

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d", &maze[i][j]);
            visited[i][j] = 0; // 지나온 곳 표시하는 배열 초기화
        }
    }

    if(findExit(0, 0))
        printf("Exit found!\n"); // 탈출구를 찾았을 때
    else    
        printf("No exit!\n"); // 탈출구를 찾지 못했을 때
    return 0;
}
*/

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


