#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n + 1] = {}, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = a[i - 1] + x;
        if (a[i] >= 0) ans = max(ans, i);
    }
    cout << ans << endl;
    return 0;
}