#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    n = 100;
    int a[n + 1];
    a[0] = 1; a[1] = 2;
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + i;
        // cout << a[i] << endl;
    }
    cout << a[n] << endl;
    return 0;
}