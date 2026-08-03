#include <bits/stdc++.h>
using namespace std;

int a[] = {0, 1, 5, 7, 10, 15, 20, 28, 37};

int main()
{
    int k;
    cin >> k;
    int l = 0, r = 8, pos = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (a[mid] >= k)
        {
            pos = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << pos << "\n";
    cout << a[pos] << "\n";
    return 0;
}