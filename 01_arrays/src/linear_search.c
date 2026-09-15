
// 자료구조및알고리즘이해 수업

#include <stdio.h>

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    int n = 5;
    int key = 40;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            printf("Index : %d\n", i);
            break;
        }
    }

    return 0;
}