#include <bits/stdc++.h>
using namespace std;

int dp[1010];

int main()
{
    int n, t;
    cin >> n >> t;
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = t; j >= x; j--)
        {
            dp[j] += dp[j - x];
        }
    }
    cout << dp[t] << endl;
    return 0;
}