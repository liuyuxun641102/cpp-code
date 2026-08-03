#include <bits/stdc++.h>
using namespace std;

struct node{int x, y, z;};

int n;
vector<node> e;
int fa[105];

void init()
{
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
}

int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void unin(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y) fa[y] = x;
}

bool cmp(node a, node b) {return a.z < b.z;}

int main()
{
    cin >> n;
    init();
    int x;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> x;
            e.push_back({i, j, x});
        }
    }
    sort (e.begin(), e.end(), cmp);
    long long s = 0, c = 0;
    for (int i = 1; i <= e.size(); ++i)
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
    cout << s << endl;
    return 0;
}