#include <bits/stdc++.h>
using namespace std;

long long f(int m, int n, int st)
{
    int cnt = 0;
    if (n == 1) return 1;
    if (m == 0) return 0;
    for (int i = st; i <= m / 2; i++)
    {
        cnt += f(m - i, n - 1, i);
    }
    return cnt;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> m >> n;
        cout << f(m, n, 0) << endl;
    }
    return 0;
}