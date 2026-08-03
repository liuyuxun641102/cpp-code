#include <bits/stdc++.h>
using namespace std;

int f(string s)
{
    string a = s.substr(0, s.size() / 2);
    string b = s.substr(s.size() / 2);
    reverse(b.begin(), b.end());
    if (a != b)
    {
        return s.size();
    }
    return f(a);
}

int main()
{
    string s;
    cin >> s;
    cout << f(s);
    return 0;
}