#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int x, sum = 0;
	vector<int> ans;
	for (int i = 0; i < 7; i++)
	{
		cin >> x;
		if (x % 2 == 0)
		{
			continue;
		}
		else
		{
			ans.push_back(x);
			sum += x;
		}
	}
	if (ans.size() == 0)
	{
		cout << "-1" << endl;
		return 0;
	}
	sort(ans.begin(), ans.end());
	cout << sum << endl << ans[0] << endl;
	return 0;
}