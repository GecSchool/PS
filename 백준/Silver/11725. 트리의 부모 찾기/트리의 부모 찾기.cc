#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int ans[100001] = {
    0,
};
bool check[100001] = {
    true,
};
vector<int> node[100001];

void dfs(int n)
{
    while (!node[n].empty())
    {
        int child = node[n].back();
        node[n].pop_back();
        if (!check[child])
        {
            check[child] = true;
            ans[child] = n;
            dfs(child);
        }
    }
}

int main()
{
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        node[a].push_back(b);
        node[b].push_back(a);
    }
    dfs(1);
    for (int i = 2; i <= n; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}