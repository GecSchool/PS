#include <stdio.h>
#define MAX_INDEX 9
int num[MAX_INDEX];
int visited[MAX_INDEX];
int arr[MAX_INDEX];
int n, m;

void merge(int data[], int p, int q, int r)
{
    int i = p, j = q + 1, k = p;
    int tmp[MAX_INDEX]; // 새 배열
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
void dfs(int);
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
    }
    mergeSort(num, 1, n);
    dfs(0);
    return 0;
}
void dfs(int len)
{
    if (len == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", num[arr[i]]);
        printf("\n");
        return;
    }
    int exNum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && exNum != num[i])
        {
            visited[i] = 1;
            arr[len] = i;
            exNum = num[i];
            dfs(len + 1);
            visited[i] = 0;
        }
    }
}
