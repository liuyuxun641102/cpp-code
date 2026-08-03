#include <bits/stdc++.h>
using namespace std;

int dp[500005], a[500005];

int main()
{
    int n;
    cin >> n;
    // vector<int> a(n);
    for (int i = 1; i <= n; i++) cin >> a[i];
    // vector<int> dp(n);
    for (int i = 1; i <= n; i++) dp[i] = 1;

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > dp[ans])
        {
            ans++;
            dp[ans] = a[i];
        }
        else
        {
            for (int j = 0; j <= ans; j++)
            {
                if (dp[j] > a[i])
                {
                    dp[j] = a[i];
                    break;
                }
            }
        }
    }
    cout << n - ans << endl;
    return 0;
}