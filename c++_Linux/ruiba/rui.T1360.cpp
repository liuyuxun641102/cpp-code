#include <bits/stdc++.h>
using namespace std;

const int d[2] = {1, -1};

int arr[205];
int vis[205];
int n, a, b;

queue<int> q;

int bfs(int st)
{
    q.push(st);
    vis[st] = 0;
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        if (tmp == b) return vis[tmp];
        for (int i = 0; i < 2; i++)
        {
            int x = tmp + arr[tmp] * d[i];
            if (x < 1 || x > n) continue;
            if (vis[x]) continue;
            vis[x] = vis[tmp] + 1;
            q.push(x);
        }
    }
    return -1;
}

int main()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int ans = bfs(a);
    cout << ans << endl;
    return 0;
}