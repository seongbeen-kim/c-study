
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Example {
    int number;
    char name[10];
};

int main(void)
{
    // 구조체 포인터 선언
    struct Example *p;

    // struct Example 2개를 저장할 메모리 동적 할당
    p = (struct Example *)malloc(2 * sizeof(struct Example));

    // 메모리 할당 실패 확인
    if (p == NULL)
    {
        fprintf(stderr, "메모리 할당 실패\n");
        return 1;
    }

    // 첫 번째 구조체
    p->number = 1;
    strcpy(p->name, "Park");

    // 두 번째 구조체
    (p + 1)->number = 2;
    strcpy((p + 1)->name, "Kim");

    // 저장된 내용 출력
    printf("첫 번째 구조체\n");
    printf("number : %d\n", p->number);
    printf("name   : %s\n\n", p->name);

    printf("두 번째 구조체\n");
    printf("number : %d\n", (p + 1)->number);
    printf("name   : %s\n", (p + 1)->name);

    // 동적 할당한 메모리 반납
    free(p);

    // 해제한 메모리를 다시 가리키지 않도록 NULL 처리
    p = NULL;

    return 0;
}