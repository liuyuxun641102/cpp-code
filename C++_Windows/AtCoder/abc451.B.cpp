#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m, 0), b(m, 0);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x - 1]++;
        b[y - 1]++;
    }
    for (int i = 0; i < m; i++)
    {
        cout << b[i] - a[i] << '\n';
    }
    return 0;
}
