#include <bits/stdc++.h>
using namespace std;

int g[210][210], fa[210], n;

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
                    g[i][j] = 1;
                }
            }
        }
    }
}

int main()
{
    int tmp;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        while (cin >> tmp)
        {
            if (tmp == 0) break;
            g[i][tmp] = 1;
        }
        g[i][i] = 1;
    }
    floyd();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (g[i][j])
            {
                fa[j] = fa[i];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (fa[i] == i)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}