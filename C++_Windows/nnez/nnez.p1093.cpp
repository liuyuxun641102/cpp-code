#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string ans = "", tmp = "";
    int p1 = 0, p2;
    for (int i = 0; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
        {
            if (!tmp.empty())
            {
                int len = stoi(tmp);
                for (int j = 1; j <= len; j++)
                {
                    ans = ans + s[i];
                }
                tmp = "";
            }
            else
            {
                ans = ans + s[i];
            }
        }
        if (isdigit(s[i]))
        {
            tmp = tmp + s[i];
        }
    }
    cout << ans << endl;
    return 0;
}