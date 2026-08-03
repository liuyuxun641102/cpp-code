#include <bits/stdc++.h>
using namespace std;

struct Node {int p, c;};

bool cmp(Node a, Node b) {return a.c < b.c;}

bool check(vector<int> a, int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (a[i] >= a[1]) return 0;
    }
    return 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Node> a(m);
    vector<int> b(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].p >> a[i].c;
        b[a[i].p]++;
    }
    sort(a.begin(), a.end(), cmp);
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        if (check(b, n))
        {
            cout << sum << endl;
            return 0;
        }
        b[a[i].p]--;
        b[1]++;
        a[i].p = 1;
        sum += a[i].c;
    }
    cout << sum << endl;
    return 0;
}