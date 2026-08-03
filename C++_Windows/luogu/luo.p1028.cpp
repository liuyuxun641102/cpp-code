#include <bits/stdc++.h>
using namespace std;

int ff[1005];

int f(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (ff[n] != 0) return ff[n];
    int ans = 1;
    for (int i = 1; i <= n / 2; i++)
    {
        ans += f(i);
    }
    ff[n] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}