#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a[n];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x - 1].push_back(y);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}