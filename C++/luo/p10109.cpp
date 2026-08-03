#include <bits/stdc++.h>
using namespace std;

int n, q;
int f[305];

bool find(int x, int i)
{
    if (x == i) return 1;
    if(f[x] == x) return x;
    return find(f[x], i);
}

int main()
{
    cin >> n;
    f[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        cin >> f[i];
    }
    cin >> q;
    int m;
    while (q--)
    {
        cin >> m;
        vector<int> a(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            bool f = 1;
            for (int j = 0; j < m; ++j)
            {
                if (!find(a[j], i))
                {
                    f = 0;
                    break;
                }
            }
            if (f) ans = max(ans, i);
        }
        cout << ans << endl;
    }
    return 0;
}