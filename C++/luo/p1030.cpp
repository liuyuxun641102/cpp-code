#include <bits/stdc++.h>
using namespace std;

void f(string zx, string hx)
{
    cout << hx.back();
    int pos = zx.find(hx.back());
    string l2 = hx.substr(0, pos);
    string l1 = zx.substr(0, pos);
    if (!l1.empty())f(l1, l2);
    string r2 = hx.substr(pos, hx.size() - pos - 1);
    string r1 = zx.substr(pos + 1);
    if (!r1.empty()) f(r1, r2);
}

int main()
{
    string a, b;
    cin >> a >> b;
    f(a, b);
    return 0;
}