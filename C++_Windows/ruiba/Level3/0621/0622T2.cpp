#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;

int n, m, ans;
int dp[N][N];

string s, t;

int main()
{
    cin >> s >> t;
    n = s.size();
    m = t.size();
    s = " " + s;
    t = " " + t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i] == t[j])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            else
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}