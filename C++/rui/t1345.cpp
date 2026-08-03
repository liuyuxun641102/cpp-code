#include <bits/stdc++.h>
using namespace std;

struct node{int v, w;};

struct node2
{
    int d, u;
    bool operator > (node2 b) const
    {
        return d > b.d;
    }
};

int n, p, c;
int cows[805];
int dis[805];
bool vis[805];

vector<node> e[805];

void dijkstra(int s)
{
    memset(dis, 0x7f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<node2, vector<node2>, greater<node2>> pq;
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        node2 tmp = pq.top();
        pq.pop();
        int u = tmp.u;
        if (vis[u]) continue;
        vis[u] = 1;
        for (int j = 0; j < e[u].size(); ++j)
        {
            int v = e[u][j].v, w = e[u][j].w;
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p >> c;
    int u, v, w;
    memset(cows, 0, sizeof(cows));
    for (int i = 0; i < n; ++i)
    {
        cin >> u;
        cows[u]++;
    }

    for (int i = 0; i < c; ++i)
    {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    long long ans = LLONG_MAX, sum;
    for (int i = 1; i <= p; ++i)
    {
        dijkstra(i);
        sum = 0;
        for (int j = 1; j <= p; ++j)
        {
            sum += cows[j] * dis[j];
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}