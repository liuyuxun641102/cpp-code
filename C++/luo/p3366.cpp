#include <bits/stdc++.h>
using namespace std;

struct node{int x, y, z;};

node e[200010];
int n, m;
int fa[50005];

bool cmp(node p, node q)
{
    return p.z < q.z;
}

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
    cin >> n >> m;
    inint();
    for (int i = 1; i <= m; ++i)
    {
        cin >> e[i].x >> e[i].y >> e[i].z;
    }
    sort (e + 1, e + m + 1, cmp);
    long long s = 0, c = 0;
    for (int i = 1; i <= m; ++i)
    {
        int u = e[i].x, v = e[i].y;
        if (find(u) != find(v))
        {
            c++;
            s += e[i].z;
            unin(u, v);
            if (c == n - 1) break;
        }
    }
    if (c == n - 1) cout << s << endl;
    else cout << "orz" << endl;
    return 0;
}