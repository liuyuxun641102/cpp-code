#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> e[n];
    while (m--)
    {
        int a, x, y;
        cin >> a >> x >> y;
        if (a == 0) e[x].push_back(y);
        else
        {
            e[x].push_back(y);
            e[y].push_back(x);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        sort (e[i].begin(), e[i].end());
        cout << i << ": ";
        for (int x : e[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}