#include <bits/stdc++.h>
using namespace std;

struct node{int v; double w;};

int n, m;
int a, b;

vector<node> e[2005];

double dis[2005]; 
bool vis[2005];

void dijkstra()
{
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i <= n; ++i) dis[i] = 0.0;
    dis[a] = 1;
    for (int i = 1; i < n; ++i)
    {
        int u = -1;
        double maxn = -1.0;
        for (int j = 1; j <= n; ++j)
        {
            if (!vis[j] && dis[j] > maxn)
            {
                maxn = dis[j];
                u = j;
            }
        }
        if (u == -1) break;
        vis[u] = 1;
        for (int j = 0; j < e[u].size(); ++j)
        {
            int v = e[u][j].v;
            double w = e[u][j].w;
            if (dis[u] * w > dis[v])
            {
                dis[v] = dis[u] * w;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        double ww = (100 - w) / 100.0;
        e[u].push_back({v, ww});
        e[v].push_back({u, ww});
    }
    cin >> a >> b;
    dijkstra();
    cout << fixed << setprecision(8) << 100.0 / dis[b] << endl;
    return 0;
}