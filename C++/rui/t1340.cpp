#include <bits/stdc++.h>
using namespace std;

struct tree
{
    char data;
    int l, r;
};

string a;
tree t[10005];
int i = -1;

void f(int u)
{
    ++i;
    if (i >= a.size()) return;
    t[u].data = a[i];
    if (a[i] == '.')
    {
        return;
    }
    else
    {
        t[u].l = 2 * u;
        t[u].r = 2 * u + 1;
        f(t[u].l);
        f(t[u].r);
    }
}

void zx(int u)
{
    if (t[t[u].l].data != '.') zx(t[u].l);
    cout << t[u].data;
    if (t[t[u].r].data != '.') zx(t[u].r);
}

void hx(int u)
{
    if (t[t[u].l].data != '.') hx(t[u].l);
    if (t[t[u].r].data != '.') hx(t[u].r);
    cout << t[u].data;
}

int main()
{
    cin >> a;
    f(1);

    zx(1);
    cout << endl;
    hx(1);
    cout << endl;
    return 0;
}