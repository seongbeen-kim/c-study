
// 초급문제는 피보나치, 최대공약수 정도의 난이도가 출제 된다
// 중간고사에서는 미로에서 출구를 찾아라가 중급 문제로 나온다.(대략 2~3문제 나온다)
// 킬러 1개 출제될 예정

// 자료구조및알고리즘이해 재귀 문제 모음집 //

/*
재귀는 함수가 자기자신을 부르는 형태이다.

재귀의 대표적인 문제는 최대공약수, 팩토리얼, 거듭제곱, 피보나치 수열, 하노이 탑이 있다. 
재귀에 대해서 코드를 작성할 수 있어야 하고, 반복(for,while)문으로도 작성할 수 있어야 한다.
*/

/*

// 재귀코딩 테스트 문제 1번
// 이동 비용이 있는 하노이의 탑 문제
// o(2^n)
// 이동횟수: 2^n -1
// 1.(n-1)개가 a(from)-->b(tmp)이동 2.n번째 갈려있는 1개가 a(from)-->c(to)이동 3.(n-1)개가 b(tmp)-->c(to)이동
// hanoi 함수에서 교수님이 짜신 코드랑 약간의 차이가 있으니 시험기간때 다시 확인해보자!!!!!!!!!!!!

#include <stdio.h>
int count = 0; // 총 이동횟수를 저장
int cost = 0; // 총 이동비용을 저장

// 하노이 타워는 딱히 return하는 값이 없고 그 안에서 이동횟수와 이동비용을 출력하는 형태
// 함수에 대해서 이해가 필요하다.

void hanoi_tower(int n, char from, char tmp, char to)
{
    if(n == 1)
    {
        printf("Disc %d: %c --> %c \n", n, from, to);
        count++;
        cost+=n;
        return; 
    }

    hanoi_tower(n-1, from, to, tmp);
    printf("Disc %d: %c --> %c\n", n, from, to);
    count++;
    cost+=n;
    hanoi_tower(n-1, tmp, from, to);
}

int main()  
{
    int n;
    printf("How many disc: ");
    scanf("%d", &n); //원판의 개수를 입력받음

    hanoi_tower(n, 'A', 'B', 'C'); 
    // 원판의 개수와 기둥 이름을 전달
    // A: 시작 기둥(출발점), B: 보조 기둥(임시), C: 목표 기둥(도착점)

    // 총 이동횟수와 총 이동비용을 출력해야 한다. 그래서 count와 cost를 전역변수로 설정했다.

    printf("Total Move: %d \n", count);
    printf("Total Cost: %d \n", cost);

    return 0;
}

*/

/*
// 재귀코딩 테스트 문제 2번
// 로봇팔의 원판 이동(하노이 탑 문제에서 확장된 문제)
// 로봇팔의 구조상 부품은 인접한 기둥사이에서만 이동할 수 있다
// o(3^n)
// 이동횟수: 3^n -1

// 1. (n-1)개 A->B->C 2. n번째의 1개 A->B 3. (n-1)개 C->B->A
// 4. n번째의 1개 B->C 5. (n-1)개 A->B->C
// hanoi 함수에서 교수님이 짜신 코드랑 약간의 차이가 있으니 시험기간때 다시 확인해보자!!!!!!!!!!!!

#include <stdio.h>
int count = 0; // 총 이동횟수를 저장
int cost = 0; // 총 이동비용을 저장

// 하노이 타워는 딱히 return하는 값이 없고 그 안에서 이동횟수와 이동비용을 출력하는 형태
// 함수에 대해서 이해가 필요하다.

void hanoi_tower(int n, char from, char tmp, char to)
{
    if(n == 1)
    {
        printf("Disc %d: %c -->%c\n", n, from, tmp);
        printf("Disc %d: %c -->%c\n", n, tmp, to);
        count+=2;
        cost+=2*n;
        return; 
    }

    hanoi_tower(n-1, from, tmp, to); // n-1개를 from에서 to로 이동
    printf("Disc %d: %c -->%c\n", n, from, tmp); // n번 원판을 from에서 tmp로 이동
    hanoi_tower(n-1, to, tmp, from); // n-1개를 to에서 from로 이동
    printf("Disc %d: %c -->%c\n", n, tmp, to); // n번 원판을 tmp에서 to로 이동
    count+=2;
    cost+=2*n;
    hanoi_tower(n-1, from, tmp, to); // n-1개를 from에서 to로 이동
}

int main()
{
    int n;
    printf("Input Disc: ");
    scanf("%d", &n); //원판의 개수를 입력받음

    hanoi_tower(n, 'A', 'B', 'C'); 
    // 원판의 개수와 기둥 이름을 전달
    // A: 시작 기둥(출발점), B: 보조 기둥(임시), C: 목표 기둥(도착점)

    // 총 이동횟수와 총 이동비용을 출력해야 한다. cost와 count를 전역변수로 설정해야 한다.
    printf("Total Move: %d \n", count);
    printf("Total Cost: %d \n", cost);

    return 0;
}
*/

/*

// 재귀코딩 테스트 문제 3번
// 2XN 타일 채우기(피보나치 아이디어!!)
// 2XN 타일을 1X2, 2X1로 채울 수 있는 모든 방법의 수를 찾아야 한다!!

// N=1, N=2, N=3부터 각각의 경우를 따져보는 게 좋다.
// N=1-->1, N=2-->2, N=3-->N(2)+N(1), N(4)-->N(3)+N(2) 
// 이를 통해 피보나치 아이디어 파악하기!!
// 시간 복잡도 o(2^n), gpt한테 물어보니까 엄밀하게는 시간복잡도가 틀렸다고 하는데...(질문하기!!)

#include<stdio.h>

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

// 만약 N=30인데 1초안에 구현하라고 하면 반복문을 사용해서 풀어야 한다.
// 그 이유는 시간 복잡도 2^30이기 때문에 1초안에 못 들어갈 확률이 높다. 

// 아래는 반복문으로 구현하는 코드이다. 시간 복잡도 o(n)

#include<stdio.h>

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

    printf("Total: %d\n", b);

    return 0;
}

// 강의 노트는 배열과 재귀를 사용해서 구현했다.
// 메모이제이션을 사용한 재귀 DP, DP의 한 종류이다!!
// 시간 복잡도 o(n)

#include<stdio.h>

long long int memo[100]; // 전역 배열이라 자동으로 0으로 초기화된다.

long long tile(int n) // 재귀 함수
{
    if(n==1) return 1; // 기저 조건
    if(n==2) return 2; // 기저 조건
    if(memo[n] != 0) return memo[n]; // 이미 계산한 값이면 재귀 안돌고 바로 반환
    memo[n] = tile(n-1)+tile(n-2); // 아직 계산 안 했던 값이라면 재귀로 계산
    return memo[n];
}

int main()
{
    int n;
    printf("Input N: ");
    scanf("%d", &n);
    printf("Total: %lld\n", tile(n));

    return 0;
}
*/

/*

// 재귀코딩 테스트 문제 4번
// 합이 S가 되는 부분 수열의 개수 구하기
// 자주 나오는 코딩 테스트 문제이고 응용 및 확장이 많이 된다
// 부분수열(부분집합) 완전탐색(브루트포스)을 재귀로 구현한 코드
// 시간 복잡도 o(2^n)

// 해당 코드를 모르겠으면 영상 강의로 복습하기!!!!!!!!!

#include<stdio.h>
#define MAX 31

int a[MAX];
int count = 0;
int n, s;

void subset(int index, int sum)
{
    // 모든 원소에 대한 선택이 끝난 경우
    // index가 n이 되면 재귀 종료
    // sum은 부분수열의 합이 나올 수 있는 경우의 수로, 합이 s가 되는 케이스는 count++를 시키고 재귀 종료!!

    if(index == n)
    {
        if(sum==s)
        {
        count++; 
        }
        return;
    }

    subset(index+1, sum); // 현재 원소를 선택하지 않는 경우
    subset(index+1, sum+a[index]); // 현재 원소를 선택한 경우
}

int main(void)
{
    printf("Input N, S: ");
    scanf("%d %d", &n, &s);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    // 여기서부터 시작인데 진짜진짜 중요하다.
    subset(0, 0); // index , sum

    printf("Total: %d\n", count); 

    return 0;
}

*/

/*

// 재귀코딩 테스트 문제 5번
// 미로에서 출구를 찾아라(중요한 문제)

// 중간고사 이후에 자료구조에서 그래프, 트리를 배우게 된다.
// 거기서 가장 중요한 알고리즘이 2개 있다. 바로 탐색알고리즘인데 DFS, BFS이다.
// 그래프를 우리가 탐색할 때는 제일 먼저 만나는 탐색 알고리즘이 DFS, BFS이다.

// DFS = depth first search(깊이 우선 탐색), depth - 재귀로 구현함
// BFS = breadth first search(너비 우선 탐색), breadth - while문으로 구현함
// 문제 출제 빈도는 BFS >> DFS

// 미로에서 출구를 찾는 문제는 DFS에서 가장 기본적인 출발점을 다루는 문제이다.

////////////////// 문제 풀이 전략 /////////////////

// x-1 위, x+1 아래, y+1 오른쪽, y-1 왼쪽
// 종료조건은 X<0이거나 X>=N이거나 Y<0이거나 Y>=M인 경우가 있다.
// x,y가 이동한 곳이 1이면 종료조건이다.(벽이기 때문에)
// 지나온 곳에 대한 표시가 필요하다. 
// 처음 배열을 0으로 초기화하고 지나온 곳은 1로 표시한다.
// x,y가 이미 방문한 경우도 종료를 해야한다.
// 마지막 출력할 때는 실패하면 0, 성공하면 1이 출력된다.

// 팀 프로젝트에서는 지역변수 사용하지만, 혼자는 전역변수 사용할 수 있다.
// 문제가 발달되서 대각선으로 이동이 가능한다면 움직임에 대한 조건이 4개 더 추가된다.


#include<stdio.h>
#define MAX 20

int n, m;
int maze[MAX][MAX]; // 행(세로), 열(가로)
int visited[MAX][MAX]; // 지나온 곳 표시하기 위해 선언

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

    return 0;

///////////////// 대각선으로 이동이 되는 경우///////////////////

    // 상하좌우 이동하는경우
    //if(findExit(x-1,y)) return 1;
    //if(findExit(x+1,y)) return 1;
    //if(findExit(x,y-1)) return 1;
    //if(findExit(x,y+1)) return 1;
    
    // 대각선 이동하는 경우
    //if(findExit(x-1,y-1)) return 1;
    //if(findExit(x-1,y+1)) return 1;
    //if(findExit(x+1,y-1)) return 1;
    //if(findExit(x+1,y+1)) return 1;
    
    // 위와 같이 if구문 8번을 돌려도 되지만 배열+반복문을 사용해도 된다.


    //int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}; 
    //int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1}; 
    //for(int i=0; i<8; i++)
    //{
    //    if(findExit(x+dx[i], y+dy[i]))
    //        return 1;
    //}   

    // return 0;

    // 재귀는 반드시 종료조건이 있어야 한다. 
    // 재귀는 문자값이 줄어들어야 한다.
    // 문자값이 늘어난다면 그에 대한 종료조건이 필요하다.

    //////////////////////////////////////////////////////////////

}

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

