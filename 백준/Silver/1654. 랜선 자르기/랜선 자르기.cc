#include <iostream>
#include <vector>
#include <stdio.h>
#define MAX_SIZE 10000
#define INT_MAX 2147483647
using namespace std;

vector<long> arr(MAX_SIZE);
long t;
bool check(long lenght, long n)
{
    long numOfLan = 0;
    for (long i = 0; i < t; i++)
    {
        numOfLan += arr[i] / lenght;
    }
    return n <= numOfLan;
}
long biSearch(long right, long n)
{
    long left = 1;
    long ans = 1;
    while (left <= right)
    {
        long mid = (right + left) / 2;
        if (check(mid, n))
        {
            left = mid + 1;
            ans = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

int main()
{
    long n;
    scanf("%ld %ld", &t, &n);
    for (long i = 0; i < t; i++)
    {
        scanf("%ld", &arr[i]);
    }

    long ans = biSearch(INT_MAX, n);
    cout << ans;
    return 0;
}