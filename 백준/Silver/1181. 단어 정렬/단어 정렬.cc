#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int compare(string a, string b)
{
    if (a.length() == b.length())
    {
        return a < b;
    }
    else
    {
        return a.length() < b.length();
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        cout << arr[i] << endl;
    }
    return 0;
}