#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main()
{
    int n, m;
    cin >> n;
    char a[105][105];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> m;
    if (m == 1)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (a[i][j] == '@')
                    ans++;
        cout << ans << endl;
        return 0;
    }
    for (int day = 2; day <= m; day++)
    {
        char old[105][105];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                old[i][j] = a[i][j];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (old[i][j] == '@')
                {
                    for (int d = 0; d < 4; d++)
                    {
                        int ni = i + dx[d], nj = j + dy[d];
                        if (ni >= 1 && ni <= n && nj >= 1 && nj <= n && old[ni][nj] == '.')
                        {
                            a[ni][nj] = '@';
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == '@')
                ans++;
    cout << ans << endl;

    return 0;
}