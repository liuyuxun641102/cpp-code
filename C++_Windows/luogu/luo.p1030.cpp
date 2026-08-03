#include <bits/stdc++.h>
using namespace std;

void f(string a, string b)
{
    if (a.size() == 1 && b.size() == 1)
    {
        cout << a[0];
        return;
    }
    int p;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[b.size() - 1])
        {
            p = i;
            break;
        }
    }
    cout << b[b.size() - 1];
    string ca, da;
    if (p != 0)
    {
        ca = a.substr(0, p);
    }
    if (p != a.size() - 1)
    {
        da = a.substr(p + 1);
    }
    int p1;
    if (!ca.empty())
    {
        string cb;
        cb = b.substr(0, ca.size());
        f(ca, cb);
    }
    if (!da.empty())
    {
        string db;
        if (ca.empty())
        {
            db = b.substr(0, da.size());
        }
        else
        {
            db = b.substr(ca.size(), da.size());
        }
        f(da, db);
    }
}

int main()
{
    string a, b;
    cin >> a >> b;
    f(a, b);
    return 0;
}