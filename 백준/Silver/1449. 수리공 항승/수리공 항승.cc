#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, m;
	vector<int> n_spot;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int spot;
		cin >> spot;
		n_spot.push_back(spot);
	}

	sort(n_spot.begin(), n_spot.end());
	int cnt = 0;
	int t;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			t = n_spot[i] + m - 1;
			cnt++;
			continue;
		}
		if (t > n_spot[i])
		{
			continue;
		}
		if (t < n_spot[i])
		{
			t = n_spot[i] + m -1;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
