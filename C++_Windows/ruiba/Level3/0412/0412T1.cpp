#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a;
    for (int i = 1; i <= 10; i++)
    {
        a.push_back(i * i);
    }
    for (int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}