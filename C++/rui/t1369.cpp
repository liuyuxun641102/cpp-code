#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        q.push(t);
    }
    long long sum = 0;
    for (int i = 1; i <= n - 1; ++i)
    {
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        sum += x + y;
        q.push(x + y);
    }
    cout << sum << endl;
    return 0;
}