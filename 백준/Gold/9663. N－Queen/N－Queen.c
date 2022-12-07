#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 15
int board[MAX_SIZE];
int n, ans;
void dfs(int);

int main()
{
    scanf("%d", &n);
    dfs(0);
    printf("%d\n", ans);
}
int check(int num)
{
    for (int i = 0; i < num; i++)
    {
        if (board[i] == board[num] || num - i == abs(board[i] - board[num]))
        {
            return 0;
        } // 1.
    }
    return 1;
}
void dfs(int Qnumer)
{
    if (Qnumer == n)
    {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        board[Qnumer] = i;
        if (check(Qnumer))
        {
            dfs(Qnumer + 1);
        }
    }
}
