#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, minn = 100, maxn = -1;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        minn = min(minn, a[i]);
        maxn = max(a[i], maxn);
    }
    cout << (maxn - minn) * 2;
    return 0;
}