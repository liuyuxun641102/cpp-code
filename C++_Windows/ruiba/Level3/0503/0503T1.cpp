#include <bits/stdc++.h>
using namespace std;

int has[100];
int vis[100];

int cnt, n, m;
// void dfs(int pos)
// {
//     if (pos == n)
//     {
//         cnt++;
//         // for (int i = 1; i <= 4; ++i) cout << has[i] << " ";
//         // cout << endl;
//         return;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         if (vis[i]) continue;
//         has[pos] = i;
//         vis[i] = true;
//         dfs(pos + 1);
//         vis[i] = false;
//         has[pos] = 0;
//     }
// }
int k = 0;
void dfs1(int pos, int x)
{
    // if (pos == n) cout << n << '=';
    // if (pos == 0)
    // {
    //     // cnt++;
    //     // for (int i = 1; i <= m; ++i) cout << setw(3) << has[i];
    //     cout << endl;
    //     return;
    // }
    // for (int i = 1; i <= pos; i++)
    // {
    //     if (vis[i]) continue;
    //     has[pos] = i;
    //     vis[i] = true;
    //     cout << (pos == n ? "" : "+") << i;
    //     dfs1(pos - i, i);
        
    //     vis[i] = false;
    //     has[pos] = 0;
    // }
    if (pos == 0)
    {
        int sum = 0;
        if (k == 1) return;
        cout << n << "=";
        for (int i = 0; i <= n; i++)
        {
            if (i != 0) cout << '+';
            cout << has[i];
            sum += has[i];
            if (sum == n) break;
        }
        cout << endl;
        return;
    }
    for (int i = x; i <= pos; i++)
    {
        // if (pos == n) cout << n << '=';
        has[k] = i;
        // cout << (pos == n ? "" : "+") << i;
        k++;
        dfs1(pos - i, i);
        k--;
        has[k] = 0;
        // cout << endl;
    }
}

int main()
{
    cin >> n;
    // dfs(1);
    // cout << cnt << endl;
    dfs1(n, 1);
    return 0;
}