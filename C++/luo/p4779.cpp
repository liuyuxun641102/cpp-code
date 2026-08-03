#include <bits/stdc++.h>
using namespace std;

struct node
{
    int u, v, w;    
};

bool operator < (node a, node b)
{
    return a.w > b.w;
}

int n, m, s;

vector<node> e[100005];
int dis[100005], vis[100005];

priority_queue<node> q;

void dijkstra()
{
    for (int i = 0; i <= n; ++i) dis[i] = INT_MAX;
    dis[s] = 0;
    node t = {s, s, 0};
    q.push(t);
    while (!q.empty())
    {
        node t = q.top();
        q.pop();
        int u = t.v;
        if (vis[u]) continue;
        vis[u] = 1;
        for (int j = 0; j < e[u].size(); ++j)
        {
            int v = e[u][j].v, w = e[u][j].w;
            if (vis[v] == 0 && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                q.push({u, v, dis[v]});
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