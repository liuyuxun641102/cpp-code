#include <bits/stdc++.h>
using namespace std;

int g[105][105], n, lwc[105], vis[105];

int prim()
{
    int sum = 0;
    vis[1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        lwc[i] = g[1][i];
    }
    int k;
    for (int i = 1; i < n; ++i)
    {
        k = 1;
        for (int j = 2; j <= n; ++j)
            if (vis[j] == 0 && lwc[j] < lwc[k]) k = j;
        vis[k] = 1;
        sum += lwc[k];
        for (int j = 1; j <= n; ++j)
        {
            if (vis[j] == 0 && g[k][j] < lwc[j])
            {
                lwc[j] = g[k][j];
            }
        }
    }
    return sum;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> g[i][j];
            if (g[i][j] == 0)
            {
                g[i][j] = 0x7fffffff;
            }
        }
    }
    cout << prim() << endl;
    return 0;
}