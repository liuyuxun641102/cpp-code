#include <bits/stdc++.h>
using namespace std;

int g[10001][10005];
int ind[10001];
int n, m;

void dfs(int u)
{
    cout << u << " ";
    for(int v = n; v >= 1; --v)
    {
        if (g[u][v] > 0)
        {
            g[u][v]--;
            g[v][u]--;
            dfs(v);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u][v]++;
        g[v][u]++;
        ind[u]++;
        ind[v]++;
    }
    int st = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (ind[i] % 2 == 1)
        {
            st = i;
            break;
        }
    }
    dfs(st);
    return 0;
}