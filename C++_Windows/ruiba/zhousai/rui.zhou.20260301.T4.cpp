#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    sort (x.begin(), x.end());
    sort (y.begin(), y.end());

    vector<long long> prex(n + 1), prey(n + 1);
    for (int i = 1; i <= n; i++)
    {
        prex[i] = prex[i - 1] + x[i - 1];
        prey[i] = prey[i - 1] + y[i - 1];
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += x[i - 1] * (i - 1) - prex[i - 1];
        ans += y[i - 1] * (i - 1) - prey[i - 1];
    }
    cout << ans << endl;
    return 0;
}