#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    vector<int> a;
    while (q--)
    {
        int x, h;
        cin >> x >> h;
        if (x == 1)
        {
            a.push_back(h);
        }
        else if (x == 2)
        {
			sort (a.begin(), a.end());
			int l = 0, r = a.size() - 1, pos = -1;
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if (a[mid] <= h)
				{
					pos = mid;
					l = mid + 1;
				}
				else if (a[mid] > h)
				{
					r = mid - 1;
				}
			}
			cout << "   " << pos << endl;
			if (pos != -1)a.erase(a.begin(), a.begin() + pos + 1);
        }
//		for (int i : a) cout << i << " ";
//		cout << endl;
        cout << a.size() << endl;
    }
    return 0;
}
