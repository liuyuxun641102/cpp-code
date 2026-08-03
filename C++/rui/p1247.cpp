#include <bits/stdc++.h>
using namespace std;

struct node{int y, w;};

bool cmp(node a, node b)
{
    return a.y < b.y;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<node> e[n];
    while (m--)
    {
        int a, x, y, w;
        cin >> a >> x >> y >> w;
        if (a == 0)
        {
            e[x].push_back({y, w});
        }
        else
        {
            e[x].push_back({y, w});
            e[y].push_back({x, w});
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << i << ":";
        sort (e[i].begin(), e[i].end(), cmp);
        for (int j = 0; j < e[i].size(); ++j)
        {
            printf(" (%d,%d)", e[i][j].y, e[i][j].w);
        }
        cout << endl;
    }
    return 0;
}