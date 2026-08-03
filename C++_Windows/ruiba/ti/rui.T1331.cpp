#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    s.pop_back();
    stack<long long> a;
    long long x = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            x *= 10;
            x += s[i] - '0';
        }
        else if (s[i] == ' ')
        {
            a.push(x);
            x = 0;
        }
        else
        {
            int c, d;
            c = a.top();
            a.pop();
            d = a.top();
            a.pop();
            switch(s[i])
            {
                case '+' : a.push(c + d); break;
                case '-' : a.push(d - c); break;
                case '*' : a.push(c * d); break;
                case '/' : a.push(d / c); break;
            }
        }
    }
    cout << a.top() << endl;
    return 0;
}