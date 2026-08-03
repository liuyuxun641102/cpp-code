#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

struct dot {int x, y;};

int n, m, a, b;
dot x[100005], y[100005];
int vis[505][505];

int main() {
    memset(vis, -1, sizeof(vis));
    cin >> n >> m >> a >> b;

    queue<dot> q;
    for (int i = 0; i < a; i++) 
    {
        cin >> x[i].x >> x[i].y;
        if (vis[x[i].x][x[i].y] == -1) 
        {
            vis[x[i].x][x[i].y] = 0;
            q.push(x[i]);
        }
    }

    while (!q.empty()) {
        dot tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) 
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && vis[nx][ny] == -1) 
            {
                vis[nx][ny] = vis[tmp.x][tmp.y] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < b; i++) 
    {
        cin >> y[i].x >> y[i].y;
    }
    for (int i = 0; i < b; i++) 
    {
        cout << vis[y[i].x][y[i].y] << endl;
    }
    return 0;
}