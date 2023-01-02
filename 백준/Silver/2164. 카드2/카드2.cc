#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;
int n;
int ans;
queue<int> QUEUE;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        QUEUE.push(i);
    }
    int numbers = 0;
    while (QUEUE.size() > 1)
    {
        if (numbers % 2 == 0)
        {
            QUEUE.pop();
        }
        else
        {
            QUEUE.push(QUEUE.front());
            QUEUE.pop();
        }
        numbers++;
    }
    printf("%d\n", QUEUE.front());
    return 0;
}
