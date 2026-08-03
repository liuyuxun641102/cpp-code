#include <bits/stdc++.h>
using namespace std;

struct dot {int x, y;};

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

char a[45][45];

int bfs(int x, int y, int xx, int yy)
{
    queue<dot> q;
    int vis[45][45];
    memset(vis, 0, sizeof(vis));
    vis[0][0] = 1;
    q.push({x, y});
    while (!q.empty())
    {
        dot tmp = q.front();
        q.pop();
        if (tmp.x == xx && tmp.y == yy) return vis[tmp.x][tmp.y];
        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            if (nx < 0 || nx > xx || ny < 0 || ny > yy) continue;
            if (vis[nx][ny]) continue;
            if (a[nx][ny] == '#') continue;
            vis[nx][ny] = vis[tmp.x][tmp.y] + 1;
            q.push({nx, ny});
        }
    }
    return 0;
}

int main()
{
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << bfs(0, 0, r - 1, c - 1) << endl;
    return 0;
}