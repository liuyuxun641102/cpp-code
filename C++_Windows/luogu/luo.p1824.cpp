#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];
int m;
int l, r, pos;

bool check(int x)
{
    int cnt = 1, len = 0;
    for (int i = 2; i <= n; ++i)
    {
        len += (a[i] - a[i - 1]);
        if (len >= x)
        {
            cnt += 1;
            len = 0;
        }
    }
    if (cnt >= m) return true;
    else return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    l = 1, r = a[n] - a[1], pos = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            pos = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << pos << endl;
    return 0;
}