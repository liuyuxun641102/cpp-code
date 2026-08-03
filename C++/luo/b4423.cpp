#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005], b[100005];
string s;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    cin >> s;
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'a') st.push(1);
        else if (s[i] == 'b') st.push(2);
        else if (isdigit(s[i]))
        {
            ans *= 10;
            ans += s[i] - '0';
        }
    }
    while (!st.empty())
    {
        if (st.top() == 1)
        {
            ans = a[ans];
        }
        else
        {
            ans = b[ans];
        }
        st.pop();
    }
    cout << ans << endl;
    return 0;
}