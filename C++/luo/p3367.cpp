#include <bits/stdc++.h>
using namespace std;

int n, m, fa[200005];

void inint()
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
    }
}

int find(int x)
{
    if (fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

void unin(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y) fa[y] = x;
}

int main()
{
    int z, x, y;
    cin >> n >> m;
    inint();
    while (m--)
    {
        cin >> z >> x >> y;
        if (z == 1) unin(x, y);
        else if (z == 2)
        {
            if (find(x) == find(y)) cout << "Y\n";
            else cout << "N\n";
        }
    }
    return 0;
}