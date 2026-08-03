#include <bits/stdc++.h>
using namespace std;

double dis[105][105], x[505], y[505];

int n, m;

void floyd()
{
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) 
    {
        cin >> x[i] >> y[i];
    }
    cin >> m;
    memset(dis, 127, sizeof(dis));
    while (m--)
    {
        int i, j;
        cin >> i >> j;
        double t = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        dis[i][j] = dis[j][i] = t;
    }
    floyd();
    int s, t;
    cin >> s >> t;
    cout << fixed << setprecision(2) << dis[s][t] << endl;
    return 0;
}