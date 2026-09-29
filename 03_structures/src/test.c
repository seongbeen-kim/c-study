 
// 배열과 구조체 test 문제 모음집

/*

// 가장 가까운 두 점 찾기(쉬운 문제) - 브루트포스 문제
// o(n^2)

#include <stdio.h>
#include <math.h>
#define MAX 100

typedef struct{    // typedef는 main밖에서 선언하는 경우가 많다.
    int id; // 점 번호
    int x;  // x좌표
    int y;  // y좌표
} Point;


int main()
{
    Point p[MAX];   // 구조체 배열 선언
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d", &p[i].id, &p[i].x, &p[i].y);
    }

    double min_dist = 10000; // 최소 거리를 모르니까 나올 수 있는 경우중 가장 큰 값을 커버할 수 있는 값을 작성
    int p1 = -1 , p2 = -1; // id값이 들어간다.

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int dx = p[i].x - p[j].x;
            int dy = p[i].y - p[j].y;
            double dist = sqrt(dx*dx+dy*dy); //sqrt의 반환값의 type은 double
            if(min_dist>dist)
            {
                min_dist = dist;
                p1 = p[i].id;
                p2 = p[j].id;
            }
        }
    }

    printf("Closest Points: %d %d\n", p1, p2);
    printf("Distance: %.3lf\n", min_dist);

    return 0;
}
*/

/*

// 강의노트 풀이(전반적으로 안전하다)

#include <stdio.h>
#include <math.h>
#define MAX 100

typedef struct {
    int id;
    int x;
    int y;
} Point;

int main(void)
{
    Point p[MAX];
    int n;
    int p1 = 0, p2 = 1;
    double minDist, dist;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &p[i].id, &p[i].x, &p[i].y);

    int dx = p[0].x - p[1].x;
    int dy = p[0].y - p[1].y;
    minDist = sqrt(dx * dx + dy * dy); // 처음부터 실제로 존재하는 두 점 p[0], p[1] 사이의 거리를 최소 거리로 잡음

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            dx = p[i].x - p[j].x;
            dy = p[i].y - p[j].y;
            dist = sqrt(dx * dx + dy * dy);

            if (dist < minDist)
            {
                minDist = dist;
                p1 = i;
                p2 = j;
            }
        }
    }

    printf("Closest Points: %d %d\n", p[p1].id, p[p2].id); // id가 아닌 배열의 인덱스를 저장함
    printf("Distance: %.3f\n", minDist);

    return 0;
}

*/

//////////////////////////////////////////////////////////////////////////////////////////

/*

// 최대 회의 수 선택하기(중간 문제) - 백준 기준으로 실버정도 레벨
// 그리디 알고리즘의 대표 문제인 ‘회의실 배정(Activity Selection)’ 문제
// 강의노트에서는 선택정렬로 코드 작성되어 있음

// 목표는 서로 시간이 겹치지 않는 회의를 최대한 많이 선택하는 것이야.
// 여기서 가장 중요한 그리디 전략은 현재 선택할 수 있는 회의 중 가장 빨리 끝나는 회의를 선택한다.
// 왜냐하면 일찍 끝나는 회의를 선택하면 뒤에 다른 회의를 넣을 수 있는 시간이 가장 많이 남기 때문이다.
// 그리디는 현재 상황에서 가장 좋아 보이는 선택을 하고, 이전 선택을 되돌리지 않는 알고리즘

// 종료시간을 기준으로 회의실 배치해야 한다(중요중요)
// 1. 구조체 배열에 회의 저장 2. end 기준으로 오름차순 정렬
// 3. 첫 번째 회의 선택 4. 나머지 회의를 순서대로 확인

// o(n^2)

#include <stdio.h>
#define MAX 100

typedef struct {
    int id;
    int start;
    int end;
} Meet;

int main()
{
    Meet m[MAX];
    int n;
    int count = 0;
    int lastEnd = -1; // 마지막으로 선택한 회의의 종료 시간

    scanf("%d", &n);

    // 회의 정보 입력
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d",
              &m[i].id,
              &m[i].start,
              &m[i].end);
    }

    // 종료시간 기준 버블 정렬
    // 버블 정렬은 서로 인접한 두 원소를 계속 비교해서 큰 값을 뒤로 보내는 방식이다.
    for (int i = 0; i < n - 1; i++) // 반복문 조건이 꽤나 중요하다!!
    {
        for (int j = 0; j < n - 1 - i; j++) // 반복문 조건이 꽤나 중요하다!!
        {
            // 종료시간이 더 늦으면 교환
            if (m[j].end > m[j + 1].end)
            {
                Meet temp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = temp;
            }

            // 종료시간이 같으면 시작시간이 더 늦은 회의를 뒤로
            // 시작시간도 오름차순으로 정렬시키기
            else if (m[j].end == m[j + 1].end &&
                     m[j].start > m[j + 1].start)
            {
                Meet temp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = temp;
            }
        }
    }

    // 회의 선택 및 출력
    printf("Selected Meetings\n");

    for (int i = 0; i < n; i++)
    {
        if (m[i].start >= lastEnd)
        {
            printf("%d : %d ~ %d\n",
                   m[i].id,
                   m[i].start,
                   m[i].end);

            lastEnd = m[i].end;
            count++;
        }
    }

    printf("Maximum Meetings: %d\n", count);

    return 0;
}

// 강의노트 풀이(선택정렬)
// o(n^2)

#include <stdio.h>
#define MAX 100

typedef struct {
    int id;
    int start;
    int end;
} Meeting;

int main(void)
{
    Meeting meeting[MAX];
    Meeting temp;

    int n;
    int count = 0;
    int lastEnd = -1;

    // 회의 개수 입력
    scanf("%d", &n);

    // 회의 정보 입력
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d",
              &meeting[i].id,
              &meeting[i].start,
              &meeting[i].end);
    }

    // 종료 시간을 기준으로 선택 정렬
    for (int i = 0; i < n - 1; i++)
    {
        int min = i; // 일단 현재로서는 meeting[i]이 가장 빨리 끝난다고 가정

        for (int j = i + 1; j < n; j++)
        {
            // 종료 시간이 더 빠른 회의 선택
            if (meeting[j].end < meeting[min].end)
            {
                min = j;
            }

            // 종료 시간이 같으면 시작 시간이 더 빠른 회의 선택
            else if (meeting[j].end == meeting[min].end &&
                     meeting[j].start < meeting[min].start)
            {
                min = j;
            }
        }

        // meeting[i]와 meeting[min] 교환
        temp = meeting[i];
        meeting[i] = meeting[min];
        meeting[min] = temp;
    }

    // 최대 회의 선택
    printf("Selected Meetings\n");

    for (int i = 0; i < n; i++)
    {
        if (meeting[i].start >= lastEnd)
        {
            printf("%d : %d ~ %d\n",
                   meeting[i].id,
                   meeting[i].start,
                   meeting[i].end);

            lastEnd = meeting[i].end;
            count++;
        }
    }

    printf("Maximum Meetings: %d\n", count);

    return 0;
}

*/

//////////////////////////////////////////////////////////////////////////////////////

/*
// 최소 회의실 수 구하기(어려운 문제)
// 시작시간을 기준으로 회의실을 배치해야 한다(중요중요)
// start 기준 정렬 → 회의가 시작될 때 비어 있는 방이 있는지 확인

// 버블 정렬

#include <stdio.h>
#define MAX 100

typedef struct {
    int id;
    int start;
    int end;
} Meet;

int main()
{
    Meet m[MAX];
    int last[MAX] = {0}; // last는 각 회의실에서 마지막으로 배정된 회의의 종료시간을 저장한다.
    // last[r] = r번째 회의실이 몇 시부터 비는가라고 생각하면 된다.

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d",
              &m[i].id,
              &m[i].start,
              &m[i].end);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            // 앞에 있는 회의가 더 늦게 시작한다면 교환함(start 오름차순)
            // 시작시간이 같다면 종료시간이 빠른 걸 앞으로(start가 같으면 end 오름차순)
            if (m[j].start > m[j + 1].start ||
               (m[j].start == m[j + 1].start &&
                m[j].end > m[j + 1].end)) 
            {
                Meet tmp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = tmp;
            }
        }
    }

    // 첫 번째 회의는 첫 번째 회의실 사용
    int count = 1; // count = 현재 사용 중인 회의실 개수
    last[0] = m[0].end; // 첫 번째 회의는 무조건 회의실 하나가 필요하니 첫 번째 회의를 Room 0에 넣는다.

    // 나머지 회의 배정
    for (int i = 1; i < n; i++)
    {
        int r;

        // 사용할 수 있는 기존 회의실 탐색
        for (r = 0; r < count; r++)
        {
            if (m[i].start >= last[r])
            {
                last[r] = m[i].end;
                break;
            }
        }

        // 사용할 수 있는 방이 없으면 새 회의실 추가
        if (r == count)
        {
            last[count] = m[i].end;
            count++;
        }
    }

    printf("Minimum Rooms: %d\n", count);

    return 0;
}

*/

/*
    
// 강의노트(선택정렬)

-----------------------------복습이 꽤나 필요한 코드 !!!!!! ---------------------------------

// 회의 정보 입력 -> 회의를 시작시간 기준으로 정렬 
// -> 각 회의를 기존 회의실에 넣어보고, 안 되면 새 방 추가

#include <stdio.h>
#define MAX 100

typedef struct {
    int id;
    int start;
    int end;
    int room;
} Meeting;

typedef struct {
    int id; // 회의실 번호
    int end; // 그 회의실에서 현재 마지막으로 진행 중인 회의의 종료시간
} Room;

int main(void)
{
    Meeting meeting[MAX]; // 전체 회의들을 저장
    Room room[MAX]; // 만들어진 회의실들의 상태 저장
    Meeting temp; // 선택정렬할 때 회의 두 개를 교환하기 위한 임시 변수

    int n;
    int roomCount = 0; // 처음에는 회의실을 하나도 만든 게 없음

    scanf("%d", &n);

    // 회의 정보 입력
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d",
              &meeting[i].id,
              &meeting[i].start,
              &meeting[i].end);

        meeting[i].room = 0; // 아직 어떤 회의실에 배정될지 모르니까 일단 0으로 처리함
    }

    // 시작 시간 기준 선택 정렬
    // 시작 시간이 같으면 종료 시간이 빠른 순서
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (meeting[j].start < meeting[min].start)
            {
                min = j;
            }
            else if (meeting[j].start == meeting[min].start &&
                     meeting[j].end < meeting[min].end)
            {
                min = j;
            }
        }

        temp = meeting[i];
        meeting[i] = meeting[min];
        meeting[min] = temp;
    }

    // 각 회의에 회의실 배정
    for (int i = 0; i < n; i++)
    {
        int selectedRoom = -1; // 아직 사용할 회의실을 찾지 못했다.
        // 만약 selectedRoom = 2;이라면 room[2]를 사용하겠다라는 뜻이다.
        int minEnd = 999999; // 이 변수는 사용할 수 있는 회의실 중 가장 작은 종료시간을 저장하기 위한 변수
        // 처음에는 아직 아무 방도 안 봤으니까 엄청 큰 값으로 세팅한다.

        // 사용할 수 있는 기존 회의실 찾기
        for (int j = 0; j < roomCount; j++)
        {
            if (room[j].end <= meeting[i].start)
            {
                if (room[j].end < minEnd)
                {
                    minEnd = room[j].end;
                    selectedRoom = j;
                }
            }
        }

        // 사용할 수 있는 기존 회의실이 없는 경우
        if (selectedRoom == -1)
        {
            room[roomCount].id = roomCount + 1;
            room[roomCount].end = meeting[i].end;

            meeting[i].room = room[roomCount].id;

            roomCount++;
        }

        // 기존 회의실 사용
        else
        {
            meeting[i].room = room[selectedRoom].id;
            room[selectedRoom].end = meeting[i].end;
        }
    }

    printf("\nMinimum Rooms: %d\n", roomCount);

    return 0;
}
*/