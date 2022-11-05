#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> arr(10001, 0);
    for (int i = 0; i < n; i++)
    {
        int index;
        scanf("%d", &index);
        arr[index]++;
    }
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 0; j < arr[i]; j++)
            printf("%d\n", i);
    }
    return 0;
}