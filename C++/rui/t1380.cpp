#include <bits/stdc++.h>
using namespace std;

struct edge{int v, w;};

struct node
{
    int u, d;
    friend bool operator > (node a, node b)
    {
        return a.d > b.d;
    }
};

int n, m, ts, t;
int u, v;

int dis[100005];
bool vis[100005];
vector<edge> e[100005];

priority_queue<node, vector<node>, greater<node>> pq;

void dijkstra()
{
    memset(dis, 0x7f, sizeof(dis));
    dis[ts] = 0;
    pq.push({ts, 0});
    int v, w;
    while (!pq.empty())
    {
        int u = pq.top().u;
        pq.pop();
        vis[u] = 1;
        for (int i = 0; i < e[u].size(); ++i)
        {
            v = e[u][i].v;
            w = e[u][i].w;
            if (!vis[v] && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                pq.push({v, dis[v]});
            }
        }
    }
}

int main()
{
    cin >> n >> m >> ts >> t;
    while (m--)
    {
        cin >> u >> v;
        e[u].push_back({v, 1});
        e[v].push_back({u, 1});
    }
    dijkstra();
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, dis[i] + t);
    }
    cout << ans + 1 << endl;
    return 0;
}