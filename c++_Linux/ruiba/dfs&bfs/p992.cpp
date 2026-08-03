#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0};
const int dy[] = {0, 1};

int n, m;

int ans_x[100];
int ans_y[100];
int ans = 0;

void dfs(int x, int y, int dep)
{
    if (x == n && y == m)
    {
        ans++;
        cout << ans << ":";
        for (int i = 0; i < dep; i++)
        {
            if (i != 0) cout << "->";
            cout << ans_x[i] << "," << ans_y[i];
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        ans_x[dep] = nx;
        ans_y[dep] = ny;
        dfs(nx, ny, dep + 1);
        ans_x[dep] = 0;
        ans_y[dep] = 0;
    }
}

int main()
{
    cin >> n >> m;
    ans_x[0] = 1;
    ans_y[0] = 1;
    dfs(1, 1, 1);
    return 0;
}