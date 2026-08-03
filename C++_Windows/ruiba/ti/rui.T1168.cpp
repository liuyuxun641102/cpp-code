#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while (a.back() == '0' && a.size() > 1)
    {
        a.pop_back();
    }
    while (b.back() == '0' && b.size() > 1)
    {
        b.pop_back();
    }
    int lena = a.size();
    int lenb = b.size();
    int x[lena], y[lenb];
    int p = lena - 1;
    for (int i = lena - 1; i >= 0; i--) x[p--] = a[i] - '0';
    p = lenb - 1;
    for (int i = lenb - 1; i >= 0; i--) y[p--] = b[i] - '0';
    int lenc = max(lena, lenb) + 1, z[lenc] = {};
    // cout << lenc << endl;
    for (int i = 0; i < lenc - 1; i++)
    {
        if (i < lena) z[i] += x[i];
        if (i < lenb) z[i] += y[i];
        z[i + 1] += z[i] / 10;
        z[i] %= 10;
    }
    /*
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    cout << a << endl << b << endl;
    for (int i = 0; i < lena; i++)
    {
        cout << a[i];
    }
    cout << endl;
    for (int i = 0; i < lenb; i++)
    {
        cout << b[i];
    }
    cout << endl;
    */
    string c;
    for (int i = 0; i < lenc; i++)
    {
        c += char(z[i] + '0');
    }
    while (c.back() == '0' && c.size() > 1)
    {
        c.pop_back();
    }
    reverse(c.begin(), c.end());
    cout << c << endl;
    return 0;
}