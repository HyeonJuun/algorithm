#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int x; cin >> x;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			cout << 0 << '\n';
			return 0;
		}
	}
	int left = 0, right = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > x)
		{
			left = arr[i -1];
			right = arr[i];
			break;
		}
	}
	for (int i = left + 1; i < right; i++)
	{
		for (int j = i + 1; j < right; j++)
		{
			if (i <= x && x <= j)
			{
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}