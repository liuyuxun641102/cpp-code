#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n;
    cin >> n;
    n %= 26;
    for (int i = 0; i < s.size(); i++)
    {
        s[i] += n;
        if (!isupper(s[i]))
        {
            s[i] -= 26;
        }
    }
    cout << s << endl;
    return 0;
}