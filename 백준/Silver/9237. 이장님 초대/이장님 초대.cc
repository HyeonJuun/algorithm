#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

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
	sort(v.begin(), v.end(), greater<>());

	int ans = 1;
	for (int i = 0; i < v.size(); i++)
	{
		ans = max(v[i] + i+1, ans);
	}
	cout << ans + 1 << endl;
	return 0;
}