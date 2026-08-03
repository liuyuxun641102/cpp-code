#include <bits/stdc++.h>
using namespace std;

struct tree{char data, l, r;};

int n, a[100];
tree t[27];

void qx(int u)
{
    cout << t[u].data;
    if (t[u].l != '*') qx(a[t[u].l - '0']);
    if (t[u].r != '*') qx(a[t[u].r - '0']);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        char x[3];
        cin >> x[0] >> x[1] >> x[2];
        t[i].data = x[0];
        a[t[i].data - '0'] = i;
        t[i].l = x[1];
        t[i].r = x[2];
    }
    qx(1);
    return 0;
}