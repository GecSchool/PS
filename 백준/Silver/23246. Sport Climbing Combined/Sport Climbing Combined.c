#include <stdio.h>
#define size 100
typedef struct rank
{
    int number;
    int L;
    int S;
    int B;
} rank;
/**
 * input rank,rank
 * fir<=sec -> return 1
 * else return 0
 */
int fun(rank fir, rank sec)
{
    int tmpFir = fir.B * fir.L * fir.S;
    int tmpSec = sec.B * sec.L * sec.S;
    if (tmpFir < tmpSec)
    {
        return 1;
    }
    else if (tmpFir > tmpSec)
    {
        return 0;
    }
    else
    {
        int sumFir = fir.B + fir.L + fir.S;
        int sumSec = sec.B + sec.L + sec.S;
        if (sumFir < sumSec)
        {
            return 1;
        }
        else if (sumFir > sumSec)
        {
            return 0;
        }
        else
        {
            if (fir.number <= sec.number)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}

void merge(rank data[], int p, int q, int r)
{
    int i = p, j = q + 1, k = p;
    rank tmp[size]; // 새 배열
    while (i <= q && j <= r)
    {
        if (fun(data[i], data[j]))
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
void mergeSort(rank data[], int p, int r)
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
    rank p[size] = {
        0,
    };
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &p[i].number, &p[i].L, &p[i].S, &p[i].B);
    }
    mergeSort(p, 0, n - 1);
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", p[i].number);
    }
    return 0;
}