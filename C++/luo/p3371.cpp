#include <bits/stdc++.h>
using namespace std;

struct node{int u, v, w;};

int n, m, s;

vector<node> e[10005];
int dis[10005], vis[10005];

void dijkstra()
{
    for (int i = 0; i <= n; ++i) dis[i] = INT_MAX;
    dis[s] = 0;
    for (int i = 1; i < n; ++i)
    {
        int u = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (!vis[j] && dis[j] < dis[u]) u = j;
        }
        vis[u] = 1;
        for (int j = 0; j < e[u].size(); ++j)
        {
            int v = e[u][j].v, w = e[u][j].w;
            if (vis[v] == 0 && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s;
    int u, v, w;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v >> w;
        e[u].push_back({u, v, w});
    }
    dijkstra();
    for (int i = 1; i <= n; ++i)
    {
        cout << dis[i] << " ";
    }
    return 0;
}