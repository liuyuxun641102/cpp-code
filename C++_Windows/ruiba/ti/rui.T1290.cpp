#include <bits/stdc++.h>
using namespace std;

int dp[1010];

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int w, v;
        cin >> w >> v;
        for (int j = m; j >= w; --j)
        {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[m] << endl;
    return 0;
}