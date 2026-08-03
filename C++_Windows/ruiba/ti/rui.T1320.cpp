#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {cin >> a[i]; sum += a[i];}
    sort (a.begin(), a.end(), greater<int>());
    int cnt = 0;
    sum /= n;
    for (int i = 0; i < n - 1; i++)
    {
        if (i > sum)
        {
            a[i + 1] += a[i] - sum;
            a[i] = sum;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}