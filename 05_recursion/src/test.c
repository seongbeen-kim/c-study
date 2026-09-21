
// 자료구조및알고리즘이해 재귀 문제 모음집

/*
재귀는 함수가 자기자신을 부르는 형태이다.

재귀의 대표적인 문제는 최대공약수, 팩토리얼, 거듭제곱, 피보나치 수열,
하노이 탑이 있다. 

재귀에 대해서 코드를 작성할 수 있어야 하고, 반복(for,while)문으로도
작성할 수 있어야 한다.!!

재귀코딩 테스트 문제 1번

// 2^n -1

#include <stdio.h>
int count = 0; // 총 이동횟수를 저장
int cost = 0; // 총 이동비용을 저장
// 하노이 타워는 딱히 return하는 값이 없고 그 안에서 이동횟수와 이동비용을 출력하는 형태


// 함수에 대해서 이해가 필요하다.
void hanoi_tower(int n, char from, char tmp, char to)
{
    if(n == 1)
    {
        printf("Disc %d : %c -->%c \n", n, from, to")
        count++;
        cost+=n;
        return; 
    }

    hanoi_tower(n-1, from, to, tmp);
    printf("Disc %d : %c -->%c \n", n, from, to);
    count++;
    cost+=n;
    hanoi_tower(n-1, tmp, from, to);

}

int main()
{
    int n;
    printf("Input Disc: ");
    scanf("%d", &n); //원판의 개수를 입력받음

    hanoi_tower(n, 'A', 'B', 'C'); 
    // 원판의 개수와 기둥 이름을 전달
    // A: 시작 기둥(출발점), B: 보조 기둥(임시), C: 목표 기둥(도착점)

    // 총 이동횟수와 총 이동비용을 출력해야 한다. (전역변수 설정) )

    printf("Total Move: %d \n", count);
    printf("Total Cost: %d \n", cost);

    return 0;

}

재귀코딩 테스트 문제 2번

// 3^n -1

로봇팔의 원판 이동(하노이 탑 문제에서 확장된 문제)
로봇팔의 구조상 부품은 인접한 기둥사이에서만 이동할 수 있다

//  

#include <stdio.h>
int count = 0; // 총 이동횟수를 저장
int cost = 0; // 총 이동비용을 저장
// 하노이 타워는 딱히 return하는 값이 없고 그 안에서 이동횟수와 이동비용을 출력하는 형태


// 함수에 대해서 이해가 필요하다.
void hanoi_tower(int n, char from, char tmp, char to)
{
    if(n == 1)
    {
        printf("Disc %d : %c -->%c \n", n, from, tmp")
        printf("Disc %d : %c -->%c \n", n, tmp, to")
        count+=2;
        cost+=2*n;
        return; 
    }

    hanoi_tower(n-1, from, tmp, to); 
    printf("Disc %d : %c -->%c \n", n, from, tmp);
    hanoi_tower(n-1, to, tmp, from);
    printf("Disc %d : %c -->%c \n", n, tmp, to);
    count+=2;
    cost+=2*n;
    hanoi_tower(n-1, from, tmp, to);
}

int main()
{
    int n;
    printf("Input Disc: ");
    scanf("%d", &n); //원판의 개수를 입력받음

    hanoi_tower(n, 'A', 'B', 'C'); 
    // 원판의 개수와 기둥 이름을 전달
    // A: 시작 기둥(출발점), B: 보조 기둥(임시), C: 목표 기둥(도착점)

    // 총 이동횟수와 총 이동비용을 출력해야 한다. (전역변수 설정) )

    printf("Total Move: %d \n", count);
    printf("Total Cost: %d \n", cost);

    return 0;

}

재귀코딩 테스트 문제 3번

2xN 타일 채우기(피보나치 아이디어!!)

int tile(int n)
{
    if(n==1) return 1;
    if(n==2) return 2;

    return tile(n-1)+tile(n-2);
}

int main()
{
    int n, count = 0;
    printf("Input N: ");
    scanf("%d", &n);

    count = tile(n);
    printf("Total: %d\n", count);

    return 0;
}

// 만약 N=30인데 1초안에 구현하라고 하면 반복문을 사용해서 풀어야 함
// 시간 복잡도 2^30이기 때문에 1초안에 못 들어갈 확률이 높다. 
// 반복문으로 구현하는 코드이다. 시간 복잡도 o(n)
// 강의 노트는 배열을 써서 구현했다.(재귀) 시간 복잡도 o(2^n)

int main()
{
    int n;
    printf("Input N: ");
    scanf("%d", &n);

    int a = 1;
    int b = 2;
    int c;
    for(int i=3; i<=n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    printf("Total: %d\n", c);

    return 0;
}


재귀코딩 테스트 문제 4번

합이 S가 되는 부분 수열의 개수 구하기
자주 나오는 코딩 테스트 문제, 응용 및 확장이 많이 된다
시간 복잡도 o(2^n)

#include<stdio.h>
#define MAX 10

int a[max];
int count = 0;
int n, s;

void subset(int index, int sum)
{
    if(index == n)
    {
        if(sum==s)
        {
        count++; 
        }
        return;
    }

    subset(index+1, sum); //왼쪽 케이스
    subset(index+1, sum+a[index]);


}

int main(void)
{
    printf("Input N, S: ");
    scanf("%d %d", &n, &s);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    subset(0, 0); // index , subset
    printf("Total: %d\n", count); 

    return 0;
}

재귀코딩 테스트 문제 5번

미로에서 출구를 찾아라(중요한 문제)
중간고사 이후에 자료구조에서 그래프, 트리를 배우게 되는데
여기서 가장 중요한 알고리즘이 2개 있는데, 탐색알고리즘인데 dfs, bfs이다
dfs = depth first search(깊이 우선 탐색)
bfs = breadth first search(너비 우선 탐색)
그래프를 우리가 탐색할 때는 제일 먼저 만나는 탐색 알고리즘이 dfs, bfs이다

depth - 재귀로 구현함
breadth - while문으로 구현함
문제 출제 빈도는 bfs>>dfs
dfs에서 가장 기본적인 출발점을 다루는 문제임(미로에서 출구를 찾는 문제) 
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