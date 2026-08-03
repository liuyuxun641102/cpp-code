#include <bits/stdc++.h>
using namespace std;

struct node {int x, y, z;};

int n;
vector<node> e;
int f[105];

int find(int x)
{
    if (f[x] == x) return f[x];
    return f[x] = find(f[x]);
}

void unin(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) f[y] = x; 
}

int main()
{
    int x, k;
    int a, b, m, sum2 = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) f[i] = i;
    for (int i = 1; i <= k; ++i)
    {
        cin >> a >> b >> m;
        sum2 += m;
        e.push_back({a, b, m});
    }
    sort (e.begin(), e.end(), [](node a, node b){return a.z < b.z;});
    long long sum = 0, cnt = 0;
    for (int i = 0; i < e.size(); ++i)
    {
        if (find(e[i].x) != find(e[i].y))
        {
            cnt++;
            sum += e[i].z;
            unin(e[i].x, e[i].y);
        }
        if (cnt == n - 1) break;
    }
    cout << sum2 - sum << endl;
    return 0;
}