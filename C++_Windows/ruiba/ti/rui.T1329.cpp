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
int n, m;

queue<dot> q;

void bfs(int sx, int sy)
{
    q.push({sx, sy}); //把起点压入队列
    while (!q.empty())
    {
        dot tmp = q.front();
        q.pop();
        //判断终点
        // if (a[tmp.x][tmp.y] == 'T') return vis[tmp.x][tmp.y];
        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            //越界
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            //走不了
            if (vis[nx][ny] != 0 || a[nx][ny] == '0') continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
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