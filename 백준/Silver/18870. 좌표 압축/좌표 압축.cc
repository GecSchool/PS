#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, int> mapset;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    vector<int> sorted(n);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        arr[i] = tmp;
        sorted[i] = tmp;
    }
    sort(sorted.begin(), sorted.end());
    int value = 0;
    mapset.insert({sorted[0], value});
    for (int i = 1; i < n; i++)
    {
        if (sorted[i] != sorted[i - 1])
        {
            mapset.insert({sorted[i], ++value});
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << mapset.find(arr[i])->second << " ";
    }
    cout << endl;
    return 0;
}