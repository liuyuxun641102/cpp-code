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
    int x;
    cin >> n;
    for (int i = 1; i <= n; ++i) f[i] = i;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> x;
            e.push_back({i, j, x});
        }
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
    cout << sum << endl;
    return 0;
}