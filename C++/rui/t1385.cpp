#include <bits/stdc++.h>
using namespace std;

int n, m;
int g[1000][1000];
int fa[1000];

void floyd()
{
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (g[i][k] && g[k][j])
                {
                    g[i][j] = 0;
                }
                if (g[i][k] == 0 && g[k][j] == 0)
                {
                    g[i][j] = 0;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int p, x, y;
    for (int i = 1; i <= n; ++i)
        for (int j = 1 ; j <= n; ++j)
            g[i][j] = -1;
    for (int i = 1; i <= n; ++i) fa[i] = i;
    while (m--)
    {
        cin >> p >> x >> y;
        g[x][y] = p;
    }
    floyd();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (g[i][j] == 0)
            {
                fa[j] = fa[i];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (fa[i] == i) ans++;
    cout << ans << endl;
    return 0;
}