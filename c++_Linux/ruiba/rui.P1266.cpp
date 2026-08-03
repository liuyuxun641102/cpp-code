#include <bits/stdc++.h>
using namespace std;

bool isprime(int x)
{
    if (x == 1) return 0;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0) return 0;
    }
    return 1;
}

int n;
int a[20];
bool vis[20];

void dfs(int pos)
{
    if(pos == n + 1)
    {
        if (isprime(a[n] + a[1]))
        {
            for (int i = 1; i <= n; i++)
            {
                cout << a[i] << ' ';
            }
            cout << endl;
        }
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i] && isprime(a[pos - 1] + i))
        {
            a[pos] = i;
            vis[i] = 1;
            dfs(pos + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    a[1] = 1;
    vis[1] = 1;
    dfs(2);
    return 0;
}