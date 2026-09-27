
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[20];
    int score;
} Student;

int main()
{
    int n;

    printf("학생 수 입력: ");
    scanf("%d", &n);

    /* =========================
       1. 정적 할당
       ========================= */

    Student static_students[100];

    printf("\n[정적 할당 입력]\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d번째 학생\n", i + 1);

        printf("학번: ");
        scanf("%d", &static_students[i].id);

        printf("이름: ");
        scanf("%19s", static_students[i].name);

        printf("성적: ");
        scanf("%d", &static_students[i].score);
    }

    printf("\n[정적 할당 출력]\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d %s %d\n",
               static_students[i].id,
               static_students[i].name,
               static_students[i].score);
    }


    /* =========================
       2. 동적 할당
       ========================= */

    Student *dynamic_students;

    dynamic_students = malloc(n * sizeof(Student)); // malloc()는 메모리 공간을 만든 뒤 그 공간의 시작 주소를 반환한다.
    // 그래서 그 주소를 저장하려면 포인터가 필요해서 위에서 Student *dynamic_students;을 작성한 것이다.

    if (dynamic_students == NULL)
    {
        printf("메모리 할당 실패\n");
        return 1;
    }

    printf("\n[동적 할당 입력]\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d번째 학생\n", i + 1);

        printf("학번: ");
        scanf("%d", &dynamic_students[i].id);

        printf("이름: ");
        scanf("%19s", dynamic_students[i].name);

        printf("성적: ");
        scanf("%d", &dynamic_students[i].score);
    }

    printf("\n[동적 할당 출력]\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d %s %d\n",
               dynamic_students[i].id,
               dynamic_students[i].name,
               dynamic_students[i].score);
    }

    free(dynamic_students);

    return 0;
}