#include <bits/stdc++.h>
using namespace std;

struct dot{int x, y;};

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int a[101][101];
bool vis[101][101];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int x, y, xx, yy;
    cin >> x >> y >> xx >> yy;
    x--, y--, xx--, yy--;
    vis[x][y] = 1;
    queue<dot> q;
    q.push({x, y});
    string ans = "NO\n";
    if (a[x][y] == 1 || a[xx][yy] == 1)
    {
        cout << ans;
        return 0;
    }
    while (!q.empty())
    {
        dot tmp = q.front();
        q.pop();
        if (tmp.x == xx && tmp.y == yy) {ans = "YES\n"; break;}
        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] || a[nx][ny] == 1) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    cout << ans << endl;
    return 0;
}