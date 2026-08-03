#include <bits/stdc++.h>
using namespace std;

int dp[210];

int main()
{
    int m, n, t;
    cin >> m >> n >> t;
    vector<int> w[t];
    vector<int> v[t];
    for (int i = 0; i < n; ++i)
    {
        int wi, vi, pi;
        cin >> wi >> vi >> pi;
        pi--;
        w[pi].push_back(wi);
        v[pi].push_back(vi);
    }
    for (int i = 0; i < t; ++i)
    {
        for (int j = m; j >= 1; --j)
        {
            for (int k = 0; k < w[i].size(); k++)
            {
                if (j < w[i][k]) continue;
                dp[j] = max(dp[j], dp[j - w[i][k]] + v[i][k]);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}