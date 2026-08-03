#include <bits/stdc++.h>
using namespace std;

long long f(int n)
{
    if (n == 1) return 1;
    return n * f(n - 1);
}

int main()
{
    int n;
    cin >> n;
    long long ans = f(n);
    cout << ans << endl;
    return 0;
}