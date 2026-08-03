#include <bits/stdc++.h>
using namespace std;

int n, m;
int fa[100005];
char c[100005];

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
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
    }
    char t;
    int x, y;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i < n; ++i)
    {
        cin >> x >> y;
        if (c[x] == c[y]) unin(x, y);
    }
    while (m--)
    {
        cin >> x >> y >> t;
        if (find(x) == find(y) && t != c[x]) cout << 0;
        else cout << 1;
    }
    return 0;
}