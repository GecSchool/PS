#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
        return true;
    else if (a.second == b.second)
    {
        if (a.first < b.first)
            return true;
        return false;
    }
    else
        return false;
}
int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", arr[i].first, arr[i].second);
    }
    return 0;
}