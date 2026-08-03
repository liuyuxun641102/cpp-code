#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int e[105][105];
    memset (e, 0x3f, sizeof(e));
    while (m--)
    {
        int a, x, y, w;
        cin >> a >> x >> y >> w;
        if (a == 0)
        {
            e[x][y] = min(e[x][y], w);
        }
        else
        {
            e[x][y] = min(e[x][y], w);
            e[y][x] = min(e[y][x], w);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j && e[i][j] > 100) cout << 0 << " ";
            else if (e[i][j] > 100) cout << "N ";
            else cout << e[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}