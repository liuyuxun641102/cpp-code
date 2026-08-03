#include <bits/stdc++.h>
using namespace std;

int n, m;
int dis[1005];
bool vis[1005], e[1005][1005];

int main()
{
    string s;
    cin >> m >> n;
    getline(cin, s);
    vector<int> t;
    int num;
    while (m--)
    {
        getline(cin, s);
        t.clear();
        num = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (isdigit(s[i]))
            {
                num *= 10;
                num += s[i] - '0';
            }
            else
            {
                t.push_back(num);
                num = 0;
            }
        }
        t.push_back(num);
        for (int i = 0; i < t.size(); ++i)
        {
            for (int j = i + 1; j < t.size(); ++j)
            {
                e[t[i]][t[j]] = 1;
            }
        }
    }
    memset(dis, 0x7f, sizeof(dis));
    dis[1] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int u = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (!vis[j] && dis[j] < dis[u]) u = j;
        }
        vis[u] = 1;
        for (int j = 1; j <= n; ++j)
        {
            if (e[u][j])
            {
                dis[j] = min(dis[j], dis[u] + 1);
            }
        }
    }
    if (dis[n] != 0x7f7f7f7f)
    {
        cout << dis[n] - 1 << endl;
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}