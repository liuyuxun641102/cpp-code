#include <bits/stdc++.h>
using namespace std;

struct dot
{
    int x, y;
};

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
char a[110][110];
int vis[110][110];
int n, m, sx, sy, tx, ty;

queue<dot> q;

void bfs(int sx, int sy)
{
    q.push({sx, sy});
    while (!q.empty())
    {
        dot tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] != 0 || a[nx][ny] == '0') continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j]) continue;
            if (a[i][j] == '0') continue;
            ans++;
            bfs(i, j);
        }
    }
    cout << ans << endl;
    return 0;
}