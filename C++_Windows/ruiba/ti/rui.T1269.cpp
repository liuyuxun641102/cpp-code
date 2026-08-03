#include <bits/stdc++.h>
using namespace std;

int dp[6050];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int w, v, s;
        cin >> w >> v >> s;
        int cnt = 1;
        while (s)
        {
            if (s < cnt)
                break;
            s -= cnt;
            int noww = w * cnt;
            int nowv = v * cnt;
            for (int j = m; j >= noww; --j)
            {
                dp[j] = max(dp[j], dp[j - noww] + nowv);
            }
            cnt *= 2;
        }
        if (s)
        {
            int noww = w * s;
            int nowv = v * s;
            for (int j = m; j >= noww; --j)
            {
                dp[j] = max(dp[j], dp[j - noww] + nowv);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}