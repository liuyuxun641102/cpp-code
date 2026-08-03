#include <bits/stdc++.h>
using namespace std;

int n, a[105];

void q(int u)
{
    cout << a[u] << " ";
    if (2 * u <= n) q(2 * u);
    if (2 * u + 1 <= n) q(2 * u + 1);
}

void z(int u)
{
    if (2 * u <= n) z(2 * u);
    cout << a[u] << " ";
    if (2 * u + 1 <= n) z(2 * u + 1);
}

void h(int u)
{
    if (2 * u <= n) h(2 * u);
    if (2 * u + 1 <= n) h(2 * u + 1);
    cout << a[u] << " ";
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    q(1);
    cout << endl;
    z(1);
    cout << endl;
    h(1);
    cout << endl;
    return 0;
}