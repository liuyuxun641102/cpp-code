//快速幂 a ^ b % c
#include <bits/stdc++.h>
using namespace std;

int ksm(int a, int b, int mod)
{
    a %= mod;
    int res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << ksm(a, b, c);
    return 0;
}