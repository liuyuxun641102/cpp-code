#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

struct dot{int x, y;};

char a[205][205];

int bfs(int x, int y, int r, int c)
{
    queue<dot> q;
    int vis[205][205] = {0};
    
    vis[x][y] = 1;
    q.push({x, y});

    while (!q.empty())
    {
        dot tmp = q.front();
        q.pop();
        if (a[tmp.x][tmp.y] == 'E') return vis[tmp.x][tmp.y] - 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (vis[nx][ny] || a[nx][ny] == '#') continue;
            vis[nx][ny] = vis[tmp.x][tmp.y] + 1;
            q.push({nx, ny});
        }
    }
    return -1;
}

void mc()
{
    int r, c, x, y;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'S') x = i, y = j;
        }
    }
    int ans = bfs(x, y, r, c);
    if (ans == -1) cout << "oop!\n";
    else cout << ans << endl;
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