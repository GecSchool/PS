#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    queue<int> Q;
    for (int i = 1; i <= n; i++)
    {
        Q.push(i);
    }
    cout << "<";
    while (!(Q.size() == 1))
    {
        for (int i = 1; i < k; i++)
        {
            Q.push(Q.front());
            Q.pop();
        }
        printf("%d, ", Q.front());
        Q.pop();
    }
    printf("%d>\n", Q.front());
    return 0;
}