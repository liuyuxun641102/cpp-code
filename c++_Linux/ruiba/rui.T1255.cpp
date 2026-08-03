#include <bits/stdc++.h>
using namespace std;

struct dot {int x, y;};

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int a[45][45];
dot pre[45][45];

void bfs(int x, int y, int xx, int yy)
{
    queue<dot> q;
    int vis[45][45];

    memset(vis, 0, sizeof(vis));

    vis[0][0] = 1;
    pre[0][0] = {-1, -1};
    q.push({x, y});
    while (!q.empty())
    {
        dot tmp = q.front();
        q.pop();
        if (tmp.x == xx && tmp.y == yy) return;
        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            if (nx < 0 || nx > xx || ny < 0 || ny > yy) continue;
            if (vis[nx][ny]) continue;
            if (a[nx][ny] == 1) continue;
            vis[nx][ny] = vis[tmp.x][tmp.y] + 1;
            pre[nx][ny] = tmp;
            q.push({nx, ny});
        }
    }
}

int main()
{
    int r, c;
    r = 5, c = 5;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    bfs(0, 0, r - 1, c - 1);
    vector<dot> ans;
    dot p = {4, 4};
    while (p.x != -1)
    {
        ans.push_back(p);
        p = pre[p.x][p.y];
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        printf("(%d, %d)\n", ans[i].x, ans[i].y);
    }
    return 0;
}