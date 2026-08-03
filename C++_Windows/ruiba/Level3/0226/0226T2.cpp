#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, s, t, *pa, *pb;
    pa = &a;
    pb = &b;
    cin >> a >> b;
    s = *pa + *pb;
    t = *pa * *pb;
    cout << s << " " << t << endl;
    cout << pa << " " << pb;
    return 0;
}