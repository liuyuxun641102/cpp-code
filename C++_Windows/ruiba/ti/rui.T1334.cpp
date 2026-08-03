#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    int x = 0, y = 0;
    while (a.size() > 0)
    {
        if (y >= n)
        {
            y = 0;
        }
        ++x;
        if (x == m)
        {
            cout << y << ' ';
            x = 0;
        }
        else
        {
            y++;
        }
    }
    return 0;
}