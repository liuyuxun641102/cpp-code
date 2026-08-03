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

int n, m, ts, te;
int u, v, w;

int dis[2505];
bool vis[2505];
vector<edge> e[2505];

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
    cin >> n >> m >> ts >> te;
    while (m--)
    {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dijkstra();
    cout << dis[te] << endl;
    return 0;
}