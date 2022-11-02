#include <iostream>
#include <stack>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    stack<int> STACK;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        if (!(tmp))
        {
            STACK.pop();
        }
        else
        {
            STACK.push(tmp);
        }
    }
    int ans = 0;
    while (!(STACK.empty()))
    {
        ans += STACK.top();
        STACK.pop();
        /* code */
    }
    cout << ans;
    return 0;
}