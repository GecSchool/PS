#include <stdio.h>
#define size 200001
int n, m;
long long loca[size];
void merge(long long data[], int p, int q, int r)
{
    int i = p, j = q + 1, k = p;
    long long tmp[n + 1]; // 새 배열
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
void mergeSort(long long data[], int p, int r)
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
int main(void)
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &loca[i]);
    }
    mergeSort(loca, 0, n - 1);
    long long right = loca[n - 1] - loca[0];
    long long left = 0;
    long long result = 0;
    while (right >= left)
    {
        long long mid = (right + left) / 2;
        long long anc = 1;
        long long start_loca = loca[0];
        for (int i = 1; i < n; i++)
        {
            if (mid <= loca[i] - start_loca)
            {
                anc++;
                start_loca = loca[i];
            }
        }
        if (anc < m)
        { //mid is too big
            right = mid - 1;
        }
        else if (anc >= m)
        { //mid is too smalong long
            result = mid;
            left = mid + 1;
        }
    }
    printf("%lld\n", result);
    return 0;
}