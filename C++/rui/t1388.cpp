#include <bits/stdc++.h>
using namespace std;

map<string, string> fa;

string find(string x)
{
    if (fa.find(x) == fa.end())
    {
        fa[x] = x;
    }
    if (fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

int main()
{
    string a, pre;
    while (getline(cin, a))
    {
        char op = a.front();
        if (op == '$') break;
        string name = a.substr(1);
        if (op == '#')
        {
            if (fa.find(name) == fa.end()) fa[name] = name;
            pre = name;
        }
        else if (op == '+')
        {
            fa[name] = pre;
        }
        else
        {
            cout << name << " " << find(name) << '\n';
        }
    }
    return 0;
}