#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

struct Node{int x, y;};

int n, m;

vector<vector<char>> a;
vector<vector<bool>> b;
vector<vector<int>> vis;

int bfs(int x, int y)
{
    if (b[x][y]) return 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = 0;
        }
    }
    queue<Node> q;
    q.push({x, y});
    vis[x][y] = 1;
    while (!q.empty())
    {
        Node tmp = q.front();
        q.pop();
        if (b[tmp.x][tmp.y]) return vis[tmp.x][tmp.y] - 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || a[nx][ny] == 'X') continue;
            vis[nx][ny] = vis[tmp.x][tmp.y] + 1;
            q.push({nx, ny});
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<char> tmp;
        for (int j = 0; j < m; j++) tmp.push_back(0);
        a.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        vector<bool> tmp;
        for (int j = 0; j < m; j++) tmp.push_back(0);
        b.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < m; j++) tmp.push_back(0);
        vis.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    while (1)
    {
        int x, y, xx, yy;
        cin >> xx >> yy >> x >> y;
        if (x == 0 && y == 0 && xx == 0 && yy == 0) break;
        x--, y--, xx--, yy--;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                b[i][j] = 0;
        for (int i = 0; i < 8; i++)
        {
            int nx = xx, ny = yy;
            while (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (a[nx][ny] == 'X') break;
                b[nx][ny] = 1;
                nx += dx[i];
                ny += dy[i];
            }
        }
        int ans = bfs(x, y);
        if (ans == -1) cout << "Poor Harry\n";
        else cout << ans << endl;
    }
    return 0;
}