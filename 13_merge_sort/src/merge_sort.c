
// 자료구조및알고리즘이해 수업

// o(n log n) 시간복잡도

#include <stdio.h>

void merge(int a[], int left, int mid, int right)
{
    int temp[100];
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) // 두 쪽을 비교
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    // 두 쪽 중 한쪽이 남아있을 경우 대입하는 과정

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= right)
        temp[k++] = a[j++];

    for (i = left; i <= right; i++)
        a[i] = temp[i];
}

void mergeSort(int a[], int left, int right) // 재귀함수
{
    // 하나 남을 때까지 분리

    if (left < right) 
    {
        int mid = (left + right) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}

int main()
{
    int a[] = {5, 3, 8, 4, 2, 7, 1, 6};
    int n = 8;

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}