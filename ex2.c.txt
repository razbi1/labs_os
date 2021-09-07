#include <stdio.h>

int asc(int i, int j)
{
    if (i > j)
        return 1;
    else
        return 0;
}

void bubble_sort(int n, int arr[n])
{
    int     i;
    int     j;
    int     *x1;
    int     *x2;
    int     tmp;

    for (int i = 0; i < n; i++)
    {
        for ( int j = 0; j < n-i-1; j++)
        {
            if (asc(arr[j],arr[j + 1]) == 1)
            {
                x1 = &arr[j];
                x2 = &arr[j+1];
                tmp = *x1;
                *x1 = *x2;
                *x2 = tmp;
            }
        }
    }
}

int main()
{
    int     n;
    int     i;

    scanf("%d", &n);
    int     arr[n];

    for(i = 0;i < n;i++)
        scanf("%d", &arr[i]); 
    bubble_sort(n, arr);
    for(i = 0;i < n;i++)
        printf("%d", arr[i]);
    printf("\n");
    return (0);
}