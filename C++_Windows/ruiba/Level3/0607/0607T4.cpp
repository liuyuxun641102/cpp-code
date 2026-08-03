#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
struct dot{int x, y;};

char a[105][105];
int vis[105][105];

int n;

void bfs(int x, int y, int c)
{
    queue<dot> q;
    q.push({x, y});
    vis[x][y] = c;
    while (!q.empty())
    {
        dot tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] || a[tmp.x][tmp.y] != a[nx][ny]) continue;
            vis[nx][ny] = c;
            q.push({nx, ny});
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];


    memset (vis, 0, sizeof(vis));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 0)
            {
                ++ans;
                bfs(i, j, ans);
            }
        }
    }

    cout << ans << " ";

    ans = 0;
    memset (vis, 0, sizeof(vis));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 'G')
                a[i][j] = 'R';
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 0)
            {
                ++ans;
                bfs(i, j, ans);
            }
        }
    }

    cout << ans << " ";
    return 0;
}