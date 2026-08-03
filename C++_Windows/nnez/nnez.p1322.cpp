#include <bits/stdc++.h>
using namespace std;

int f(int a, int b, int c, int d)
{
    int res = 0;
    while (a != c || b != d)
    {
        if (a != c)
        {
            if (a > c)
            {
                a--;
                res ++;
            }
            else
            {
                a++;
                res ++;
            }
        }
        else
        {
            if (b > d)
            {
                b--;
                res ++;
            }
            else
            {
                b++;
                res ++;
            }
        }
        // cout << a << b << endl;
    }
    return res;
}

int main()
{
    int x, y, n;
    cin >> x >> y >> n;
    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        // cout << f(x, y, a[i][0], a[i][1]) << endl;
        if (a[i][0] == x && a[i][1] == y)
        {
            i--;
            n--;
        }
    }
    vector<vector<int>> b;
    int p = 10000000;
    for (int i = 0; i < n; i++)
    {
        int tmp = f(x, y, a[i][0], a[i][1]);
        if (tmp < p)
        {
            b.clear();
            b.push_back({a[i][0], a[i][1]});
            p = tmp;
        }
        if (tmp == p)
        {
            b.push_back({a[i][0], a[i][1]});
        }
    }
    int ax, ay;
    if (b.size() == 1)
    {
        ax = b[0][0];
        ay = b[0][1];
    }
    else
    {
        p = 10000000;
        for (int i = 0; i < b.size(); i++)
        {
            int tmp = f(0, 0, b[i][0], b[i][1]);
            // cout << b[i][0] << b[i][1] << endl;
            if (tmp < p)
            {
                ax = b[i][0];
                ay = b[i][1];
                p = tmp;
            }
        }
    }
    cout << ax << ' ' << ay << endl;
    return 0;
}