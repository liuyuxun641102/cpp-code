#include <bits/stdc++.h>
using namespace std;

struct node {int u, v, w;};

int n, m, s, t;

vector<node> e;
int dis[10005];

void bellman()
{
    memset(dis, 0x7f, sizeof(dis));
    dis[s] = 0;
    bool f;
    for (int i = 1; i < n; ++i)
    {
        f = 0;
        for (int j = 0; j < e.size(); ++j)
        {
            int u = e[j].u, v = e[j].v, w = e[j].w;
            if (dis[u] + w < dis[v])
            {
                f = 1;
                dis[v] = dis[u] + w;
            }
        }
        if (!f) break;
    }
}

int main()
{
    cin >> n >> m >> s >> t;
    int u, v, w;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        e.push_back({u, v, w});
        e.push_back({v, u, w});
    }
    bellman();
    cout << dis[t] << endl;
    return 0;
}