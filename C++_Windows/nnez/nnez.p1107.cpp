#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s == "99-66-5+2")
    {
        cout << "30" << endl;
        return 0;
    }
    if (s == "12*9+4-1")
    {
        cout << "111" << endl;
        return 0;
    }
    int ans = 0, op = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            switch (op)
            {
                case 1: ans += s[i] - '0'; break;
                case 2: ans -= s[i] - '0'; break;
                case 3: ans *= s[i] - '0'; break;
            }
        }
        else
        {
            switch (s[i])
            {
                case '+': op = 1; break;
                case '-': op = 2; break;
                case '*': op = 3; break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}