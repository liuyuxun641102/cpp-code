#include <bits/stdc++.h>
using namespace std;

int n, s;

long long a[85][85];

int main()
{
    cin >> n >> s;
    string str;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> str;
            if (str == "-")
            {
                a[i][j] = 0x7fffffffff;
            }
            else
            {
                a[i][j] = stoll(str);
            }
        }
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i == s) continue;
        printf("(%d -> %d) = %lld\n", s, i, a[s][i]);
    }
    return 0;
}