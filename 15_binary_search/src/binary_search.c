
// 자료구조및알고리즘이해 수업

// o(nlogn) 시간복잡도

#include <stdio.h>

int main()
{
    int a[] = {1, 3, 5, 7, 9, 11, 13, 15};
    // 이진탐색은 정렬된 배열에서만 사용 가능하다.

    int n = 8;
    int key = 11; // 찾고자 하는 값

    int left = 0;
    int right = n - 1; // 처음에는 배열 전체를 탐색 범위로 설정

    while (left <= right)
    {
        int mid = (left + right) / 2; // 3.5는 3이 된다. (정수형으로 변환)

        if (a[mid] == key)
        {
            printf("Index: %d\n", mid);
            break;
        }
        else if (a[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return 0;
}