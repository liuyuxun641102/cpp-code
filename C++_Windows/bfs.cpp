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

int bfs(int sx, int sy)
{
    q.push({sx, sy}); //把起点压入队列
    while (!q.empty())
    {
        dot tmp = q.front();
        q.pop();
        //判断终点
        if (a[tmp.x][tmp.y] == 'T') return vis[tmp.x][tmp.y];
        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            //越界
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            //走不了
            if (vis[nx][ny] != 0 || a[nx][ny] == '#') continue;
            vis[nx][ny] = vis[tmp.x][tmp.y] + 1;
            q.push({nx, ny});
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'S') sx = i, sy = j;
            // else if (a[i][j] == 'T') tx = i, ty = j;
        }
    }
    cout << bfs(sx, sy);
    return 0;
}