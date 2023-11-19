#include <stdio.h>
int max(int a,int b)
{
    if(a>b)
    return a;
    else return b;
}
int main()
{
    int res[200010];
    int t, n;
    scanf("%d", t);
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 200010; j++)
            res[j] = 0;
        scanf("%d", n);
        // 有正向和反向遍历两种，反向遍历有点难理解为什么要特意反向
        for (int i = 1; i <= n; i++)
        {
            int now;
            scanf("%d", &now);
            if (now)
            {
                res[max(1, i - now + 1)]++;
                res[i + 1]--;
            }
        }
        for (int i = 1; i <= n; ++i)
            res[i] = res[i] + res[i - 1];
        for (int i = 1; i <= n; ++i)
            printf("%d ", res[i] != 0);
        printf("\n");
    }
    return 0;
}
