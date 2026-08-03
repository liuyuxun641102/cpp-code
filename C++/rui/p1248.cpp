#include <bits/stdc++.h>
using namespace std;

struct node {int v, w;};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<node> e[n];
    while (m--)
    {
        int x, y, w;
        cin >> x >> y >> w;
        e[x].push_back({y, w});
        e[y].push_back({x, w});
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < e[i].size(); ++j)
        {
            printf("%d -> %d %d\n", i, e[i][j].v, e[i][j].w);
        }
    }
    return 0;
}