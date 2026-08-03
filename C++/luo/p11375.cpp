#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, s;
    cin >> n >> s;
    int t = 0;
    while (n--)
    {
        char c;
        cin >> c;
        if (c == 'U')
        {
            if (s == 1) continue;
            if (t > 0) t--;
            else s /= 2;
        }
        else if (c == 'L')
        {
            if (2 * s > 1e12)
            {
                t++;
                continue;
            }
            s *= 2;
        }
        else if (c == 'R')
        {
            if (2 * s + 1> 1e12)
            {
                t++;
                continue;
            }
            s *= 2;
            s += 1;
        }
    }
    cout << s << endl;
    return 0;
}