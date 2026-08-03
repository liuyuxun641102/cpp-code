#include <bits/stdc++.h>
using namespace std;

int a[1100];
int cnt;

void f(int n)
{
    bool flag = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        a[++cnt] = n;
        return;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            a[++cnt] = i;
            f(n / i);
            return;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    f(n);
    int t = 0, x = a[1];
    cout << endl;
    for (int i = 1; i <= cnt; ++i)
    {
        if (a[i] == x)
            t++;
        else
        {
            if (t > 1)
            {
                cout << x << "^" << t << "*";
                x = a[i];
                t = 1;
            }
            else
            {
                cout << x << "*";
                x = a[i];
                t = 1;
            }
        }
    }
    if (t > 1)
    {
        cout << x << "^" << t;
    }
    else
    {
        cout << x;
    }
    return 0;
}