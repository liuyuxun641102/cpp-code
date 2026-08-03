#include <bits/stdc++.h>
using namespace std;

int dp[10005], a[10005], pre[10005];

int main()
{
    int n;
    cin >> n;
    // vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // vector<int> dp(n);
    for (int i = 0; i < n; i++) dp[i] = 1, pre[i] = i;
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (a[j] <= a[i])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    pre[i] = j;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << "max=" << ans << endl;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == ans)
        {
            int pos = i;
            v.push_back(pos);
            while (pre[pos] != pos)
            {
                pos = pre[pos];
                v.push_back(pos);
            }
            break;
        }
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << a[v[i]] << " ";
    }
    return 0;
}