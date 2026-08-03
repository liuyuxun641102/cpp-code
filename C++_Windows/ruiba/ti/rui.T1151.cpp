#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<bool> a(n + 5, 0);
    a[1] = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (a[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                a[j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!a[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}