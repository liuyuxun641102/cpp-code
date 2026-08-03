#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        bool f = 0;
        string p, q;
        for (auto ch : s)
        {
            if (ch == '/')
            {
                f = 1;
                continue;
            }
            if (f)
            {
                q += ch;
            }
            else
            {
                p += ch;
            }
        }
        long long P = stoll(p), Q = stoll(q);
        if (!Q && P % Q)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n"
        }
    }
    return 0;
}