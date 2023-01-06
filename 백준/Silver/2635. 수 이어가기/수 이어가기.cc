#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

const int MAX = 1000 + 1;

int n;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int mx = -1;
	vector<int> ans;
	for (int i = 0; i <= n; i++)
	{
		vector<int> v;
		v.push_back(n);
		v.push_back(i);
		int x = n - i;

		while (true)
		{
			x = v[v.size() - 2] - v[v.size() - 1];
			if (x < 0)
				break;
			v.push_back(x);
		}
		if (mx < (int)v.size())
		{
			mx = v.size();
			ans.clear();
			ans.assign(v.begin(), v.end());
		}
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}