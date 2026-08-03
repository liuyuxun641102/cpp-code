#include <bits/stdc++.h>
using namespace std;

struct tree
{
    int l, r;
};

tree t[1000005];

void q(int u)
{
    cout << u << " ";
    if (t[u].l != 0) q(t[u].l);
    if (t[u].r != 0) q(t[u].r);
}

void z(int u)
{
    if (t[u].l != 0) z(t[u].l);
    cout << u << " ";
    if (t[u].r != 0) z(t[u].r);
}

void h(int u)
{
    if (t[u].l != 0) h(t[u].l);
    if (t[u].r != 0) h(t[u].r);
    cout << u << " ";
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> t[i].l >> t[i].r;
    }
    q(1);
    cout << endl;

    z(1);
    cout << endl;

    h(1);
    cout << endl;
    return 0;
}