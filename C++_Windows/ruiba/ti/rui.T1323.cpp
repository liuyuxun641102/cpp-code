#include <bits/stdc++.h>
using namespace std;

struct N{int a, b;};

bool cmp(N a, N b)
{
    if (a.b != b.b) return a.b < b.b;
    return a.a < a.a;
}

int main()
{
    int n;
    cin >> n;
    vector<N> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].a >> a[i].b;
    sort (a.begin(), a.end(), cmp);
    int ans = 0, tmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].a >= tmp)
        {
            ans++;
            tmp = a[i].b;
        }
    }
    cout << ans << endl;
    return 0;
}