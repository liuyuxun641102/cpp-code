#include <bits/stdc++.h>
using namespace std;

const int dx[] = {2, 1, 2, -1, -2, 1, -2, -1};
const int dy[] = {1, 2, -1, 2, 1, -2, -1, -2};

struct dot{int x, y;};

char a[205][205];

int bfs(int x, int y, int xx, int yy, int r)
{
    queue<dot> q;
    int vis[305][305] = {0};
    
    vis[x][y] = 1;
    q.push({x, y});

    while (!q.empty())
    {
        dot tmp = q.front();
        q.pop();
        if (tmp.x == xx && tmp.y == yy) return vis[tmp.x][tmp.y] - 1;
        for (int i = 0; i < 8; i++)
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= r) continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = vis[tmp.x][tmp.y] + 1;
            q.push({nx, ny});
        }
    }
    return 0;
}

void mc()
{
    int r, x, y, xx, yy;
    cin >> r >> x >> y >> xx >> yy;
    if (x == xx && y == yy)
    {
        cout << 0 << endl;
        return;
    }
    int ans = bfs(x, y, xx, yy, r);
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        mc();
    }
    return 0;
}