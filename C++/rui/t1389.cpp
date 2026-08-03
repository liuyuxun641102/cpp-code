#include <bits/stdc++.h>
using namespace std;

int n, m;
int fa[100005];
int sum[100005];

int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void unin(int a, int b)
{
    int x = find(a), y = find(b);
    if (x != y)
    {
        fa[y] = x;
        sum[x] += sum[y];
    }
}

int main()
{
    char op;
    int a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        sum[i] = 1;
    }
    while (m--)
    {
        cin >> op;
        if (op == 'M')
        {
            cin >> a >> b;
            unin(a, b);
        }
        else
        {
            cin >> a;
            cout << sum[find(a)] << endl;
        }
    }
    return 0;
}