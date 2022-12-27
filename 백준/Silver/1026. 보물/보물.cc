#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), compare);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i] * b[i];
    }
    printf("%d\n", ans);
    return 0;
}