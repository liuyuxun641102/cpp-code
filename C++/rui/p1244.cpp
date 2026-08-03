#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int e[105][105] = {};
    while (m--)
    {
        int a, x, y;
        cin >> a >> x >> y;
        if (a == 0) e[x][y] = 1;
        else
        {
            e[x][y] = 1;
            e[y][x] = 1;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << e[i][j];
        }
        cout << endl;
    }
    return 0;
}