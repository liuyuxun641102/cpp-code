#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, op1, op2;
    cin >> n >> k >> op1 >> op2;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<long long>> dp(op1 + 1, vector<long long>(op2 + 1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int x = op1; x >= 0; x--)
        {
            for (int y = op2; y >= 0; y--)
            {
                dp[x][y] += a[i];
                if (x > 0)
                {
                    dp[x][y] = min(dp[x][y], dp[x - 1][y] + (a[i] + 1) / 2);
                }
                if (y > 0 && a[i] >= k)
                {
                    dp[x][y] = min(dp[x][y], dp[x][y - 1] + a[i] - k);
                }
                if (x > 0 && y > 0)
                {
                    if (a[i] >= k)
                    {
                        dp[x][y] = min(dp[x][y], dp[x - 1][y - 1] + (a[i] - k + 1) / 2);
                    }
                    if ((a[i] + 1) / 2 >= k)
                    {
                        dp[x][y] = min(dp[x][y], dp[x - 1][y - 1] + (a[i] + 1) / 2 - k);
                    }
                }
            }
        }
    }
    long long ans = INT_MAX;
    for (int x = 0; x <= op1; x++)
    {
        for (int y = 0; y <= op2; y++)
        {
            ans = min(ans, dp[x][y]);
        }
    }
    cout << ans << endl;
    return 0;
}