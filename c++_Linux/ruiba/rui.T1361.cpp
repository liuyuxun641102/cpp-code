#include <bits/stdc++.h>
using namespace std;

string n;
int k;
int a[20], b[20];

int bfs()
{
    int ans = 0;
    queue<string> q;
    map<string, int> mp;
    mp[n] = 1;
    q.push(n);
    while (!q.empty())
    {
        string tmp = q.front();
        q.pop();
        ans++;
        for (int i = 0; i < tmp.size(); i++)
        {
            for (int j = 0; j < k; j++)
            {
                char c = a[j] + '0';
                if (tmp[i] == c)
                {
                    string str = tmp;
                    str[i] = char(b[j] + '0');
                    if (mp[str] != 0) continue;
                    mp[str] = 1;
                    q.push(str);
                }
            }
        }
    }
    return ans;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a[i] >> b[i];
    }
    cout << bfs() << endl;
    return 0;
}