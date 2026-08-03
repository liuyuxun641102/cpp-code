#include <bits/stdc++.h>
using namespace std;

int a[10005], cnt;

void up(int i)
{
    if (i / 2 > 0 && a[i] < a[i / 2]) 
    {
        swap(a[i], a[i / 2]);
        up(i / 2);
    }
}

void down(int i)
{
    int u = i;
    if (2 * i <= cnt && a[u] > a[2 * u]) u *= 2;
    if (2 * i + 1 <= cnt && a[u] > a[2 * u + 1]) u = 2 * u + 1;
    
    if (u != i)
    {
        swap (a[u], a[i]);
        down(u);
    }
}

void add(int x)
{
    a[++cnt] = x;
    up(cnt);
}

void del()
{
    a[1] = a[cnt];
    cnt--;
    down(1);
}

int main()
{
    int n, op, x;
    cin >> n;
    while (n--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            add(x);
        }
        else if (op == 2)
        {
            cout << a[1] << endl;
        }
        else if (op == 3)
        {
            del();
        }
    }
    return 0;
}