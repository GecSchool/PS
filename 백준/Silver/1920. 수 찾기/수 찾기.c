#include <stdio.h>
#define MAX_SIZE 100000

void merge(int data[], int p, int q, int r)
{
    int i = p, j = q + 1, k = p;
    int tmp[MAX_SIZE]; // 새 배열
    while (i <= q && j <= r)
    {
        if (data[i] <= data[j])
            tmp[k++] = data[i++];
        else
            tmp[k++] = data[j++];
    }
    while (i <= q)
        tmp[k++] = data[i++];
    while (j <= r)
        tmp[k++] = data[j++];
    for (int a = p; a <= r; a++)
        data[a] = tmp[a];
}
void mergeSort(int data[], int p, int r)
{ // 정렬하고 싶은 배열,시작점,끝점
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        mergeSort(data, p, q);
        mergeSort(data, q + 1, r);
        merge(data, p, q, r);
    }
}

int binarySearch(int right, int target, int *arr)
{
    int left = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (target > arr[mid])
        {
            left = mid + 1;
        }
        else if (target < arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n;
    int arr[MAX_SIZE] = {
        0,
    };
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        printf("%d\n", binarySearch(n - 1, tmp, arr));
    }
    return 0;
}