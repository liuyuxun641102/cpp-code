#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int vis[N];
int d[4];
int n, k;

queue<int> q;

int bfs(int x)
{
    vis[x] = 1;
    q.push(n);
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        if (tmp == k) return vis[tmp] - 1;
        d[1] = tmp - 1;
        d[2] = tmp + 1;
        d[3] = tmp * 2;
        for (int i = 1; i <= 3; i++)
        {
            int nx = d[i];
            if (nx >= 0 && nx <= N && vis[nx] == 0)
            {
                vis[nx] = vis[tmp] + 1;
                q.push(nx);
            }
        }
    }
    return 0;
}

int main()
{
    cin >> n >> k;
    if (n >= k)
    {
        cout << n - k << endl;
        return 0;
    }
    cout << bfs(n) << endl;
    return 0;
}