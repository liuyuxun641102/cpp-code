#include <bits/stdc++.h>
using namespace std;

int n;
int ind[10005], times[10005], mx[10005];
vector<int> e[10005];
queue<int> q;

int topo()
{
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (ind[i] == 0)
        {
            mx[i] = times[i];
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int i = 0; i < e[t].size(); ++i)
        {
            ind[e[t][i]]--;
            if (ind[e[t][i]] == 0)
            {
                q.push(e[t][i]);
            }
            mx[e[t][i]] = max(mx[e[t][i]], mx[t] + times[e[t][i]]);
        }
    }
    for (int i = 1; i <= n; ++i) sum = max(sum, mx[i]);
    return sum;
}

int main()
{
    cin >> n;
    int x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        cin >> x;
        times[i] = x;
        while (1)
        {
            cin >> x;
            if (x == 0) break;
            e[i].push_back(x);
            ind[x]++;
        }
    }
    cout << topo() << endl;
    return 0;
}