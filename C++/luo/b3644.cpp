#include <bits/stdc++.h>
using namespace std;

int n;
int ind[105];
vector<int> e[105];
queue<int> q;

void tops()
{
    for (int i = 1; i <= n; ++i)
    {
        if (ind[i] == 0) q.push(i);
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (int i = 0; i < e[x].size(); ++i)
        {
            ind[e[x][i]]--;
            if (ind[e[x][i]] == 0) q.push(e[x][i]);
        }
    }
}

int c[105];
stack<int> st;

void dfstopo(int x)
{
    for (int i = 0; i < e[x].size(); ++i)
    {
        if (c[e[x][i]] == 0)
        {
            dfstopo(e[x][i]);
        }
    }
    c[x] = 1;
    st.push(x);
}

int main()
{
    cin >> n;
    int x;
    for (int i = 1; i <= n; ++i)
    {
        while (1)
        {
            cin >> x;
            if (x == 0) break;
            e[i].push_back(x);
            ind[x]++;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (c[i] == 0)
        {
            dfstopo(i);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}