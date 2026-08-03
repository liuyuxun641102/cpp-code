#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, m;
    cin >> l >> m;
    vector<bool> t(l + 1, 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        for (int i = a; i <= b; i++)
        {
            t[i] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i <= l; i++)
    {
        if (t[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}