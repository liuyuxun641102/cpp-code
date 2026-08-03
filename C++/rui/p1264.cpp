#include <bits/stdc++.h>
using namespace std;

int n, m;
int vis[100005];
vector<int> g[100005];

void dfs(int x)
{
    cout << x << " ";
    for (int i = 0; i < g[x].size(); ++i)
    {
        if (vis[g[x][i]]) continue;
        vis[g[x][i]] = 1;
        dfs(g[x][i]);
    }
}

void bfs(int x)
{
    queue<int> q;
    vis[x] = 1;
    q.push(x);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        cout << t << " ";
        for (int i = 0; i < g[t].size(); ++i)
        {
            if (vis[g[t][i]]) continue;
            vis[g[t][i]] = 1;
            q.push(g[t][i]);
        }
    }
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i)
    {
        sort (g[i].begin(), g[i].end());
    }
    memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    dfs(1);
    cout << endl;
    memset(vis, 0, sizeof(vis));
    bfs(1);
    cout << endl;
    return 0;
}