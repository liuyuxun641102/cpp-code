#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    char c;
    int ans;
    priority_queue<int, vector<int>, greater<int>> q;
    while (1)
    {
        cin >> n;
        if (n == 0) break;
        for (int i = 1; i <= n; ++i)
        {
            cin >> c >> x;
            q.push(x);
        }
        ans = 0;
        while (q.size() > 1)
        {
            int a = q.top(); q.pop();
            int b = q.top(); q.pop();
            ans += a + b;
            q.push(a + b);
        }
        cout << ans << endl;
        q.pop();
    }
    return 0;
}