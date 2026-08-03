#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, less<int>> q;
    int n, m;
    cin >> n >> m;
    int a, b, c, t;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b >> c;
        for (int x = 1; x <= m; ++x)
        {
            t = a * x * x + b * x + c;
            q.push(t);
            if (q.size() > m)
            {
                q.pop();
            }
            if (t > q.top())
            {
                break;
            }
        }
    }
    int x[10005], i = 0;
    while (!q.empty())
    {
        x[++i] = q.top();
        q.pop();
    }
    for (int j = i; j >= 1; --j)
    {
        cout << x[j] << " ";
    }
    return 0;
}