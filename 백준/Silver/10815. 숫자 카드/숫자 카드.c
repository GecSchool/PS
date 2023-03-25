#include <stdio.h>
#include <string.h>
#define size 500001
int arr[size] = {
    0,
};
int binary(int rigth, int target)
{
    int left = 0;
    while (left <= rigth)
    {
        int mid = (rigth + left) / 2;
        if (arr[mid] > target)
        {
            rigth = mid - 1;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
void merge(int data[], int p, int q, int r)
{
    int i = p, j = q + 1, k = p;
    int tmp[size]; // 새 배열
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
{ //정렬하고 싶은 배열,시작점,끝점
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        mergeSort(data, p, q);
        mergeSort(data, q + 1, r);
        merge(data, p, q, r);
    }
}
int main()
{
    int n, tmp, s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, 0, n - 1);
    scanf("%d", &s);
    for (int i = 0; i < s; i++)
    {
        scanf("%d", &tmp);
        printf("%d ", binary(n, tmp));
    }
    return 0;
}