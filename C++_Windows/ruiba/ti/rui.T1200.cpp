#include <bits/stdc++.h>
using namespace std;

long long f(int a, int min)
{
    if (a == 1) return 1;
    int ans = 0;
    for (int i = min; i <= a; i++)
    {
        if (a % i == 0)
        {
            // cout << i << '*';
            ans += f(a / i, i);
            // cout << endl;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        cout << f(a, 2) << endl;
    }
    return 0;
}