
// 학생 50명 성적의 최고점/최저점/평균/중앙값을 출력하는 프로그램

#include <stdio.h>

int main()
{
    int score[50];
    int temp;
    int sum = 0;

    // 성적 입력
    for (int i = 0; i < 50; i++)
    {
        printf("%d번 학생 성적: ", i + 1);
        scanf("%d", &score[i]);

        sum += score[i];
    }

    // 오름차순 정렬 (Bubble Sort)
    for (int i = 0; i < 49; i++)
    {
        for (int j = 0; j < 49 - i; j++)
        {
            if (score[j] > score[j + 1])
            {
                temp = score[j];
                score[j] = score[j + 1];
                score[j + 1] = temp;
            }
        }
    }

    // 정렬 후
    int min = score[0];
    int max = score[49];

    double average = (double)sum / 50;
    double median = (score[24] + score[25]) / 2.0;

    printf("\n최고점: %d\n", max);
    printf("최저점: %d\n", min);
    printf("평균: %.2f\n", average);
    printf("중앙값: %.2f\n", median);

    return 0;
}