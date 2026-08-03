#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, p;
    cin >> n >> p;
    long long a[n + 5] = {}, b[n + 5] = {};
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    while (p--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        b[x] += z;
        b[y + 1] -= z;
    }
    long long ans = 2000000000000000;
    for (int i = 1; i <= n; i++)
    {
        a[i] = b[i] + a[i - 1];
        if (a[i] < ans) ans = a[i];
    }
    cout << ans << endl;
    return 0;
}