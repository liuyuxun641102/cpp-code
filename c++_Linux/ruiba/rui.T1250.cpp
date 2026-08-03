#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
const int d[] = {1, 2, 4, 8};

struct Node{int x, y;};

int m, n;
int a[55][55];
int vis[55][55];

int bfs(int x, int y)
{
    queue<Node> q;
    q.push({x, y});
    vis[x][y] = 1;
    int cnt = 1;
    while (!q.empty())
    {
        Node tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (a[tmp.x][tmp.y] & d[i]) continue;
            int aa = tmp.x + dx[i];
            int bb = tmp.y + dy[i];
            if (aa < 0 || aa >= m || bb < 0 || bb >= n) continue;
            if (vis[aa][bb]) continue;
            vis[aa][bb] = 1;
            q.push({aa, bb});
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0, max = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j]) continue;
            int x = bfs(i, j);
            ans++;
            if (x > max) max = x;
        }
    }
    cout << ans << endl << max << endl;
    return 0;
}