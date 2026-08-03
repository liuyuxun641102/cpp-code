#include <bits/stdc++.h>
using namespace std;

struct M{
	string name;
	int a, b = 0, c = 0;
};

int main()
{
	int n;
	cin >> n;
	vector<M> m(n);
	for (int i = 0; i < n; i++)
	{
		cin >> m[i].name;
	}
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		string s;
		cin >> s;
		int p;
		for (int j = 0; j < n; j++)
		{
			if(m[j].name == s)
			{
				p = j;
				break;
			}
		}
//		cout << p;
		cin >> m[p].a >> x;
		if (x == 0)
		{
			continue;
		}
		for (int j = 0; j < x; j++)
		{
			string t;
			cin >> t;
			int p1;
			for (int k = 0; k < n; k++)
			{
				if(m[k].name == t)
				{
					p1 = k;
					break;
				}
			}
			m[p1].b += m[p].a / x;
			m[p].c += m[p].a / x;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << m[i].name << " " << m[i].b - m[i].c << endl;
	}
	return 0;
}