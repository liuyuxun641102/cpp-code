#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

struct node{int x, y, t;};

int m;
int a[305][305];
bool vis[305][305];

void bfs(int x, int y)
{
    queue<node> q;
    q.push({x, y, 0});
    vis[x][y] = 1;
    while (!q.empty())
    {
        node tmp = q.front();
        q.pop();
        if (a[tmp.x][tmp.y] == -1)
        {
            cout << tmp.t << endl;
            return;
        }
        for (int i = 0; i < 4; ++i)
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            if (nx < 0 || ny < 0) continue;
            if (vis[nx][ny]) continue;
            if (a[nx][ny] != -1 && a[nx][ny] <= tmp.t + 1) continue;
            q.push({nx, ny, tmp.t + 1});
            vis[nx][ny] = 1;
        }
    }
    cout << -1 << endl;
}

int main()
{
    for (int i = 0; i <= 304; ++i)
    {
        for (int j = 0; j <= 304; ++j)
        {
            a[i][j] = -1;
        }
    }
    cin >> m;
    int x, y, t;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y >> t;
        if (a[x][y] != -1) a[x][y] = min(a[x][y], t);
        else a[x][y] = t;
        for (int j = 0; j < 4; ++j)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx < 0 || ny < 0) continue;
            if (a[nx][ny] != -1) a[nx][ny] = min(a[nx][ny], t);
            else a[nx][ny] = t;
        }
    }
    if (a[0][0] == 0) { cout << -1 << endl; return 0; }
    bfs(0, 0);
    return 0;
}