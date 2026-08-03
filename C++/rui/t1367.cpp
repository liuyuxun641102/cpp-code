#include <bits/stdc++.h>
using namespace std;

struct tree{int data, l, r;};

tree t[105];

bool flag = 0;
int ans, cnt = 0, x;

void f(int u)
{
    if (ans != 0) return;
    if (t[u].l != 0) f(t[u].l);
    cnt++;
    if (t[u].data == x)
    {
        cout << cnt << endl;
        ans = cnt;
        return;
    }
    if (t[u].r != 0) f(t[u].r);
}

int main()
{
    int n;
    cin >> n;
    cin >> x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> t[i].data >> t[i].l >> t[i].r;
    }
    f(1);
    // cout << ans << endl;
    return 0;
}