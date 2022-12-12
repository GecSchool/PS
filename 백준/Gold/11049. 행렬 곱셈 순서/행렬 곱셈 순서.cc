#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define INT_MAX 2147483647 / 5
using namespace std;

int minmult(int n, const vector<int> d)
{
    int i, j, k, diagonal;
    vector<vector<int>> M(n + 1, vector<int>(n + 1));
    for (diagonal = 1; diagonal <= n - 1; diagonal++)
    {
        for (i = 1; i <= n - diagonal; i++)
        {
            j = i + diagonal;
            int smallTmp = INT_MAX;
            int indexTmp;
            for (k = i; k <= j - 1; k++)
            {
                int tmp = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (smallTmp > tmp)
                {
                    smallTmp = tmp;
                    indexTmp = k;
                }
            }
            M[i][j] = smallTmp;
        }
    }
    return M[1][n];
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> d(n + 1);
    vector<vector<int>> P(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &d[i], &d[i + 1]);
    }
    int ans = minmult(n, d);
    cout << ans << endl;

    return 0;
}