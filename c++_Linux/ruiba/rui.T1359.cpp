#include <bits/stdc++.h>
using namespace std;

const int xx[] = {1, 0, -1, 0};
const int yy[] = {0, 1, 0, -1};

struct dot
{
    int x, y;
};

int a[15][15];
int vis[15][15];

int ans = 0;

queue<dot> q;

void bfs(int x, int y)
{
    q.push({x, y});
    while (!q.empty())
    {
        dot tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.x + xx[i];
            int ny = tmp.y + yy[i];
            if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;
            if (vis[nx][ny] != 0 || a[nx][ny] == 1) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1) vis[i][j] = 1;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            bool flag = 0;
            for (int k = 0; k < 4; k++)
            {
                int xn = i + xx[k];
                int yn = j + yy[k];
                if (xn < 0 || xn >= 10 || yn < 0 || yn >= 10) continue;
                if (a[xn][yn] == 1) {flag = 1; break;}
            }
            if (!flag) continue;
            bfs(i, j);
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (vis[i][j] == 0) ans++;
                }
            }
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}