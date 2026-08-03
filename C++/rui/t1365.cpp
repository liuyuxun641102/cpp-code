#include <bits/stdc++.h>
using namespace std;

int n;
string a;

void f(string s)
{
    if (s.size() > 1)
    {
        int mid = s.size() / 2;
        f(s.substr(0, mid));
        f(s.substr(mid));
    }
    bool I = 0, b = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '1') I = 1;
        if (s[i] == '0') b = 1;
    }
    if (I == 0) cout << 'B';
    else if (b == 0) cout << 'I';
    else cout << 'F';
}

int main()
{
    cin >> n >> a;
    n = pow(2, n);
    f(a);
    return 0;
}