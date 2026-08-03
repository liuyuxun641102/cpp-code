#include <bits/stdc++.h>
using namespace std;

int ans = 1;
int f(int n)
{
    if (n == 1) return ans;
    ans = (ans + 1) * 2;
    return f(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}