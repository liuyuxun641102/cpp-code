#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int e1[1005][1005];
    vector<int> e2[1005];
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        e1[x][y] = 1;
        e1[y][x] = 1;
        e2[x].push_back(y);
        e2[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << e1[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; ++i)
    {
        sort (e2[i].begin(), e2[i].end());
        cout << e2[i].size() << " ";
        for (int x : e2[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}