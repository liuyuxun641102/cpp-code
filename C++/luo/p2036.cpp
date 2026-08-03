#include <bits/stdc++.h>
using namespace std;

int n, s[15], b[15], minn = 0x7fffffff;

void dfs(int x, int y, int d)
{
    if (d > n)
    {
        if (!(x == 1 && y == 0))
        {
            minn = min(minn, abs(x - y));
        }
        return;
    }
    dfs(x * s[d], y + b[d], d + 1);
    dfs(x, y, d + 1);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i] >> b[i];
    dfs(1, 0, 1);
    cout << minn << endl;
    return 0;
}