#include <bits/stdc++.h>
using namespace std;

int n, m, p, q;
int fa[20005];

int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void u(int x, int y)
{
    int xx = find(x), yy = find(y);
    if (xx != yy) fa[xx] = yy;
}

int main()
{
    cin >> n >> m >> p >> q;
    for (int i = 1; i <= n + m; ++i) fa[i] = i;
    int x, y;
    for (int i = 1; i <= p; ++i)
    {
        cin >> x >> y;
        u(x, y);
    }
    for (int i = 1; i <= q; ++i)
    {
        cin >> x >> y;
        x = -x + n;
        y = -y + n;
        u(x, y);
    }
    int suma = 0, sumb = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (find(1) == find(i)) suma++;
    }
    for (int i = n + 1; i <= n + m; ++i)
    {
        if (find(n + 1) == find(i)) sumb++;
    }
    cout << min(suma, sumb) << endl;
    return 0;
}