#include <bits/stdc++.h>
using namespace std;

struct node{int x, y;};
node b[500005];
vector<int> e[500005];
stack<int> st;
int n, m, k, fa[500005], c[500005], d[500005];

int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void unin(int x, int y)
{
    x = find(x), y = find(y);
    fa[y] = x;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        cin >> b[i].x >> b[i].y;
        e[b[i].x].push_back(b[i].y);
        e[b[i].y].push_back(b[i].x);
    }
    cin >> k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> c[i];
        d[c[i]] = 1;
    }
    int cnt = 0;
    for (int i = 0; i <= n; ++i)
    {
        fa[i] = i;
    }
    for (int j = 1; j <= m; ++j)
    {
        if (!d[b[j].x] && !d[b[j].y])
        {
            if (find(b[j].x) != find(b[j].y))
            {
                unin(b[j].x, b[j].y);
                cnt++;
            }
        }
    }
    int ans = n - k - cnt;
    st.push(ans);
    for (int i = k; i > 0; --i)
    {
        int u = c[i];
        d[u] = 0;
        ans++;
        for (int j = 0; j < e[u].size(); ++j)
        {
            if (d[e[u][j]] == 0 && find(u) != find(e[u][j]))
            {
                unin(u, e[u][j]);
                cnt++;
                ans--;
            }
        }
        st.push(ans);
    }
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}