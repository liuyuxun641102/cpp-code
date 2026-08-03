#include <bits/stdc++.h>
using namespace std;

struct node{int u, v, w;};

int p, s = 26;
int vis[60];
int dis[60];
vector<node> e[60];

void dijkstra()
{
    for (int i = 0; i < 60; ++i) dis[i] = INT_MAX;
    dis[25] = 0;
    for (int i = 1; i < 60; ++i)
    {
        int u = 0;
        for (int j = 0; j < 60; ++j)
        {
            if (!vis[j] && dis[j] < dis[u]) u = j;
        }
        vis[u] = 1;
        for (int j = 0; j < e[u].size(); ++j)
        {
            int v = e[u][j].v;
            int w = e[u][j].w;
            if (!vis[v] && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            }
        }
    }
}

int main()
{
    cin >> p;
    for (int i = 0; i < p; ++i)
    {
        char u, v;
        int w;
        cin >> u >> v >> w;
        int uu, vv;
        if (isupper(u)) uu = u - 'A';
        else uu = u - 'a' + 27;
        if (isupper(v)) vv = v - 'A';
        else vv = v - 'a' + 27;
        e[uu].push_back({uu, vv, w});
        e[vv].push_back({vv, uu, w});
    }
    dijkstra();
    int ans = INT_MAX, t;
    for (int i = 0; i < 25; ++i)
    {
        if (dis[i] < ans)
        {
            ans = dis[i];
            t = i;
        }
    }
    if (t < 26)
    {
        cout << char('A' + t) << " ";
    }
    else
    {
        cout << char('a' + t - 27) << " ";
    }
    cout << ans << endl;
    return 0;
}