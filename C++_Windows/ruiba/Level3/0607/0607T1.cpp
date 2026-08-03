#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

struct dot{int x, y;};

int a, b, c, d;

int vis[10][10];

int bfs()
{
    queue<dot> q;
    
    q.push({a, b});
    vis[a][b] = 1;
    
    while (!q.empty())
    {
        dot tmp = q.front();
        q.pop();
        if (tmp.x == c && tmp.y == d) return vis[tmp.x][tmp.y] - 1;
        for (int i = 0; i < 8; i++)
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];

            if (nx < 1 || nx > 8 || ny < 1 || ny > 8) continue;
            if (vis[nx][ny]) continue;

            vis[nx][ny] = vis[tmp.x][tmp.y] + 1;
            q.push({nx, ny});
        }
    }

    return -1;
}

int main()
{
    char x, y;
    cin >> x >> y;
    a = x - 'a' + 1;
    b = y - '0';
    cin >> x >> y;
    c = x - 'a' + 1;
    d = y - '0';
    // cout << a << b << c << d;
    int ans = bfs();
    cout << ans << endl;
    // for (int i = 1; i <= 8; i ++)
    // {
    //     for (int j = 1; j <= 8; j++)
    //     {
    //         cout << vis[i][j]-1 << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}