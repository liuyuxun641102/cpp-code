#include <bits/stdc++.h>
using namespace std;

int ggcd(int a, int b)
{
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << ggcd(a, b);
    return 0;
}