#include <iostream>
#include <vector>
#include <stdio.h>
#define MAX_SIZE 101
#define NONE_CONTECT 100000000
using namespace std;
vector<vector<int>> D(MAX_SIZE, vector<int>(MAX_SIZE, NONE_CONTECT)), W(MAX_SIZE, vector<int>(MAX_SIZE, NONE_CONTECT));

void floyd(int n)
{
    for (int i = 1; i <= n; i++)
    {
        W[i][i] = 0;
        D[i][i] = 0;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (D[i][j] > D[i][k] + D[k][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                }
}

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int tmpI, tmpJ, charge;
        scanf("%d %d %d", &tmpI, &tmpJ, &charge);
        W[tmpI][tmpJ] = min(W[tmpI][tmpJ], charge);
        D[tmpI][tmpJ] = min(W[tmpI][tmpJ], charge);
    }
    floyd(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", (D[i][j] == NONE_CONTECT) ? 0 : D[i][j]);
        }
        printf("\n");
    }
    return 0;
}