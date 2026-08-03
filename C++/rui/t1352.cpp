#include <bits/stdc++.h>
using namespace std;

int n, m;
int ind[10005], f[10005];
vector<int> e[10005];

void topo()
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (ind[i] == 0)
        {
            q.push(i);
            f[i] = 100;
        }
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < e[x].size(); ++i)
        {
            ind[e[x][i]]--;
            if (ind[e[x][i]] == 0)
            {
                q.push(e[x][i]);
                f[e[x][i]] = max(f[i], f[x] + 1);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        e[b].push_back(a);
        ind[a]++;
    }
    topo();
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (f[i] == 0)
        {
            cout << "Poor Xed\n";
            return 0;
        }
        ans += f[i];
    }
    cout << ans << endl;
    return 0;
}