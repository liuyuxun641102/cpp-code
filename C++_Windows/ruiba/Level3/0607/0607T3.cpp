#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct dot{int x, y;};

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    // cout << n << endl;
    char a[10][10];
    int vis[10][10];
    memset (vis, 0, sizeof(vis));
    queue<dot> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'S')
            { 
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }
    int ans = 0;
    while (!q.empty())
    {
        dot tmp = q.front();
        q.pop();
        if (a[tmp.x][tmp.y] == 'D')
        {
            if (vis[tmp.x][tmp.y] - 1 <= x)
            {
                cout << "YES\n";
                return 0;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (a[nx][ny] == 'X') continue;
            if (vis[nx][ny] == 0) 
            {
                vis[nx][ny] = vis[tmp.x][tmp.y] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << "NO\n";
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << vis[i][j] << ' ';
    //     }
    //     return 0;
    // }
    return 0;
}