#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int a[N];

int main()
{
    int n, b, ans = 0;
    cin >> n >> b;
    a[1] = 1;
	for (int i = 2; i <= n; i++) 
    {
		if (!a[i]) 
        {
			for (int j = i; j <= n; j += i)
				a[j] = i;
		}
	}
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= b) ans++;
    }
    cout << ans << endl;
    return 0;
}