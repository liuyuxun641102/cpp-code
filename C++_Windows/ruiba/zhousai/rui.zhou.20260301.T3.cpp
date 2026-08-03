#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long ans = 0, min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        min = std::min(min + c, a[i]);
        ans += min;
    }
    cout << ans << "\n";
    return 0;
}