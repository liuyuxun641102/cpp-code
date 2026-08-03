#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int a[105][105];
int vis[105][105];
int n, m;

int dfs(int x, int y)
{
    if (vis[x][y] != -1) return vis[x][y];
    int max_step = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (a[nx][ny] > a[x][y])
        {
            max_step = max(max_step, dfs(nx, ny) + 1);
        }
    }
    return vis[x][y] = max_step;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    memset(vis, -1, sizeof(vis));
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = max(ans, dfs(i, j));

    cout << ans << endl;
    return 0;
}