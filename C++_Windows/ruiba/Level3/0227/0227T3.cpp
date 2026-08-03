#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n + 5] = {}, b[n + 5] = {};
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    while (m--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        b[l] += k;
        b[r + 1] -= k;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + b[i];
        cout << a[i] << ' ';
    }
    return 0;
}