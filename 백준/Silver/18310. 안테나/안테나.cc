#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	ans = v[(n - 1) / 2];
	cout << ans << endl;
	return 0;
}