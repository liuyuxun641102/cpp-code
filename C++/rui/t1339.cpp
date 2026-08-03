#include <bits/stdc++.h>
using namespace std;

void f(string qx, string zx)
{
    int pos = zx.find(qx[0]);
    string l1 = qx.substr(1, pos);
    string l2 = zx.substr(0, pos);
    if (!l1.empty())f(l1, l2);
    string r1 = qx.substr(pos + 1);
    string r2 = zx.substr(pos + 1);
    if (!r1.empty()) f(r1, r2);
    cout << qx[0];
}

int main()
{
    string a, b;
    cin >> a >> b;
    f(a, b);
    return 0;
}