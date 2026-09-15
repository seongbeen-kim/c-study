
// 자료구조및알고리즘이해 수업

// o(n^2) 시간복잡도

#include <stdio.h>

int main()
{
    int a[] = {5, 3, 8, 4, 2};
    int n = 5;
    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            // swap 코드 써야함!!
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}