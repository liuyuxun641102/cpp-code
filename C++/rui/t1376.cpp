#include <bits/stdc++.h>
using namespace std;

int n, m;
long long e[105][105];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            e[i][j] = INT_MAX;
    for (int i = 1; i <= n; ++i) e[i][i] = 0;
    int u, v, w;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        e[u][v] = w;
        e[v][u] = w;
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
            }
        }
    }
    long long ans = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (e[1][i] == INT_MAX)
        {
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, e[1][i]);
    }
    cout << ans << endl;
    return 0;
}