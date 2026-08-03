#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 0; i < 100; i ++) {for (int j = 0; j < 100; j++) dp[i][j] = INT_MAX;}
    dp[0][0] = 0;
    for (int x = 1; x <= k; ++x)
    {
        int a, b, c;
        cin >> a >> b >> c;
        for (int i = m; i >= 0; --i)
        {
            for (int j = n; j >= 0; --j)
            {
                if (dp[i][j] == INT_MAX) continue;
                int ni = min(m, i + a);
                int nj = min(n, j + b);
                dp[ni][nj] = min(dp[ni][nj], dp[i][j] + c);
            }
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}