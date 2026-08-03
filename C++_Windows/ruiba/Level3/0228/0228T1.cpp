#include <bits/stdc++.h>
using namespace std;

struct stu
{
    int classs;
    int index;
    string name;
};

bool cmp (stu a, stu b)
{
    if (a.classs != b.classs) return a.classs < b.classs;
    return a.index < b.index;
}

int main()
{
    int n;
    cin >> n;
    stu a[n + 5] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].classs >> a[i].index >> a[i].name;
    }
    sort (a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << a[i].classs << " " << a[i].index << " " << a[i].name << endl;
    }
    return 0;
}