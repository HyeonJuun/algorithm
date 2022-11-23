#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<queue>

using namespace std;

const int MAX = 100000 + 1;

int n;

bool cmp(string a, string b)
{
	if (a.length() == b.length())
	{
		int asum = 0, bsum = 0;
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] > '0' && a[i] <= '9')
				asum += a[i] - '0';
		}
		for (int i = 0; i < b.length(); i++)
		{
			if (b[i] > '0' && b[i] <= '9')
				bsum += b[i] - '0';
		}
		if (asum != bsum)
			return asum < bsum;
		else
			return a < b;
	}
	return a.length() < b.length();
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<string> g;
	for (int i = 0; i < n; i++)
	{
		string gName;	
		cin >> gName;
		g.push_back(gName);
	}
	sort(g.begin(), g.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << g[i] << '\n';
	return 0;
}