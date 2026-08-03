#include <bits/stdc++.h>
using namespace std;

struct Node{int a, b;};

int vis[200][200];

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    queue<Node> q;
    q.push({0, 0});
    vis[0][0] = 1;   // 初始步数为1

    while (!q.empty())
    {
        Node tmp = q.front();
        q.pop();

        if (tmp.a == z || tmp.b == z)
        {
            cout << vis[tmp.a][tmp.b] - 1;
            return 0;
        }
        
        Node d[6];
        
        d[0].a = x;
        d[0].b = tmp.b;

        d[1].a = tmp.a;
        d[1].b = y;

        d[2].a = 0;
        d[2].b = tmp.b;
        
        d[3].a = tmp.a;
        d[3].b = 0;
        
        int xx = min(tmp.a, y - tmp.b);
        d[4].a = tmp.a - xx;
        d[4].b = tmp.b + xx;
        
        xx = min(tmp.b, x - tmp.a);
        d[5].a = tmp.a + xx;
        d[5].b = tmp.b - xx;

        for (int i = 0; i < 6; i++) 
        {
            int na = d[i].a, nb = d[i].b;
            if (vis[na][nb] == 0)
            {
                vis[na][nb] = vis[tmp.a][tmp.b] + 1;
                q.push({na, nb});
            }
        }
    }
    cout << "No Solution!\n";
    return 0;
}