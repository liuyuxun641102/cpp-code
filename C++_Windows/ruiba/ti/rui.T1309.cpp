#include <bits/stdc++.h>
using namespace std;

string add(string a, string b, int n)
{
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
    for (int i = 0; i < lenc - 1; i++)
    {
        if (i < lena) z[i] += x[i];
        if (i < lenb) z[i] += y[i];
        z[i + 1] += z[i] / n;
        z[i] %= n;
    }
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
    return c;
}
 
bool f(string a)
{
    string b = a;
    reverse(b.begin(), b.end());
    return b == a;
}

int main()
{
    string a;
    int n;
    cin >> n >> a;
    int ans = 0;
    while (ans <= 30 && !f(a))
    {
        string b = a;
        reverse(b.begin(), b.end());
        a = add(a, b, n);
        ans++;
    }
    if (ans == 31)
    {
        cout << "Impossible\n";
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}