#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> q;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    int ans = 0;
    while (q.size() > 1)
    {
        int a = q.top();q.pop();
        int b = q.top();q.pop();
        ans += a + b;
        q.push(a + b);
    }
    cout << ans << endl;
    return 0;
}