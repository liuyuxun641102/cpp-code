#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string t;
    int ans, max = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            t = t + s[i];
        }
        else if (!t.empty())
        {
            int tmp = stoi(t);
            if (tmp > max)
            {
                max = tmp;
                ans = i - t.size() + 1;
            }
            t = "";
        }
    }
    cout << ans << endl;
    return 0;
}