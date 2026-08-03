#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> a, int l, int mid, int m)
{
	int cnt = 0, t = 0;
//	a.push_back(l)/;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] - t < mid)
		{
			cnt++;
		}
		else
		{
			t = a[i];
		}
	}
	if (l - t < mid) cnt++;
	return cnt <= m;
}

int main()
{
	int ll, n, m;
	cin >> ll >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int l = 1, r = ll, ans;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(a, ll, mid, m))
		{
			ans = mid;
//			cout << ans << endl;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
