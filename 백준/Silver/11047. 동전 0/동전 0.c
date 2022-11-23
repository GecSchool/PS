#include <stdio.h>
int main()
{
    int n, k, m = 0;
    int coin[10] = {
        0,
    };
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &coin[i]);
    for (int i = n - 1; i >= 0; i--)
    {
        m += k / coin[i];
        k %= coin[i];
    }
    printf("%d\n", m);
    return 0;
}