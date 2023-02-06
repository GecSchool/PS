#include <stdio.h>
#define size 50
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
int cal_sum(int data[], int top, int max_one)
{
    int sum = 0;
    for (int i = top - 1; i >= 0; i -= max_one)
    {
        sum += 2 * data[i];
    }
    return sum;
}
int main()
{
    int n, k, p_top = 0, m_top = 0, ans = 0;
    int plus[size] = {
        0,
    };
    int minus[size] = {
        0,
    };
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        if (tmp > 0)
        {
            plus[p_top] = tmp;
            p_top += 1;
        }
        else if (tmp < 0)
        {
            minus[m_top] = tmp * (-1);
            m_top += 1;
        }
    }
    mergeSort(plus, 0, p_top - 1);
    mergeSort(minus, 0, m_top - 1);
    ans += cal_sum(plus, p_top, k);
    ans += cal_sum(minus, m_top, k);
    ans -= (plus[(p_top != 0) ? p_top - 1 : 0] > minus[(m_top != 0) ? m_top - 1 : 0]) ? plus[p_top - 1] : minus[m_top - 1];
    printf("%d\n", ans);
    return 0;
}