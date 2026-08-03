#include <bits/stdc++.h>
using namespace std;

vector<int> a[105];
int vis[105];

int bfs(int x)
{
    queue<int> q;
    q.push(x);
    int cnt = 0;
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < a[tmp].size(); i++)
        {
            int nx = a[tmp][i];
            if (vis[nx]) continue;
            vis[nx] = 1;
            q.push(nx);
        }
    }
    return cnt;
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int ans = 0, maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        vis[i] = 1;
        ans++;
        int now = bfs(i);
        if (now > maxn) maxn = now;
    }
    cout << ans << " " << maxn << "\n";
    return 0;
}