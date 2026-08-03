#include <bits/stdc++.h>
using namespace std;

struct N{int t, x;};

bool cmp(N a, N b)
{
    return a.t < b.t;
}

int main()
{
    int n;
    cin >> n;
    vector<N> a(n);
    for (int i = 0; i < n; i++) {cin >> a[i].t; a[i].x = i + 1;};
    sort (a.begin(), a.end(), cmp);
    int pre = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cout << a[i].x << ' ';
        if (i != 0) pre += a[i].t;
        ans += pre;
    }
    double x = ans * 1.0 / n;
    printf("\n%lf\n", x);
    return 0;
}