#include <bits/stdc++.h>
using namespace std;

struct node
{
    string name; 
    int x;
};

bool operator < (node a, node b)
{
    return a.x < b.x;
}

int main()
{
    priority_queue<node> q;
    int n;
    cin >> n;
    while (n--)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            string name;
            int x;
            cin >> name >> x;
            q.push({name, x});
        }
        else
        {
            if (q.empty()) cout << "none\n";
            else
            {
                cout << q.top().name << " " << q.top().x << endl;
                q.pop();
            }
        }
    }
    return 0;
}