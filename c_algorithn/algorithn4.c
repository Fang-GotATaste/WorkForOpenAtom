#include <stdio.h>
int n, m;
int main()
{
    scanf("%d %d", &n, &m);
    int dsu[n + 1];
    int rank[n + 1];
    for (int i = 1; i <= n; i++)
    {
        rank[i] = 1;
        dsu[i] = i;
    }

    int find(int i)
    {
        if (dsu[i] == i)
            return i;
        else
        {
            dsu[i] = find(dsu[i]);
            return dsu[i];
        }
    }

    int merge(int i, int j)
    {
        int rooti = find(i), rootj = find(j);
        if (rank[rooti] <= rank[rootj])
            dsu[rooti] = rootj;
        else
            dsu[rootj] = rooti;
        if (rank[rooti] == rank[rootj] && rooti != rootj)
            rank[rootj]++;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        merge(x, y);
        int now = find(1);
        int check = 0;
        for (int j = 2; j <= n; j++)
        {
            now = find(j);
            if (now != find(j - 1))
            {
                check = 1;
                break;
            }
        }
        if (check == 0)
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}