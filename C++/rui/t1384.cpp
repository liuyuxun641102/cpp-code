#include <bits/stdc++.h>
using namespace std;

int n, m;
bool a[105][105];

void floyd()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                if (a[j][i] && a[i][k])
                {
                    a[j][k] = 1;
                }
            }
        }
    }
}

int main()
{
    int x, y;
    cin >> n >> m;
    while (m--)
    {
        cin >> x >> y;
        a[x][y] = 1;
    }
    floyd();
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        x = 0, y = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j]) y++;
            if (a[j][i]) x++;
        }
        if (x > (n - 1) / 2 || y > (n - 1) / 2)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}