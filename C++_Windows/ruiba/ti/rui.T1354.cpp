#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<char> a;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')' || s[i] == ']')
        {
            if (a.empty())
            {
                cout << "Wrong\n";
                return 0;
            }
            if (a.top() == '(' && s[i] == ')')
            {
                a.pop();
            }
            else if (a.top() == '[' && s[i] == ']')
            {
                a.pop();
            }
            else
            {
                cout << "Wrong\n";
                return 0;
            }
        }
        else
        {
            a.push(s[i]);
        }
    }
    cout << (a.empty() ? "OK\n" : "Wrong\n");
    return 0;
}