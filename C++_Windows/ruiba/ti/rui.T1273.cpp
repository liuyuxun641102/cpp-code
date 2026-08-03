#include <bits/stdc++.h>
using namespace std;

long long dp[100000];

int main()
{
    int n, m;
    cin >> n >> m;
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = x; j <= m; j++)
        {
            dp[j] += dp[j - x];
        }
    }
    cout << dp[m] << endl;
    return 0;
}