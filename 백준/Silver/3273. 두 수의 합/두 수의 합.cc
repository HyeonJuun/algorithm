#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<queue>

using namespace std;

const int MAX = 100000 + 1;

int n, x, cnt = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cin >> x;
	sort(v.begin(), v.end());
	int left = 0, right = n - 1;
	while (left < right)
	{
		int sum = v[left] + v[right];
		if (sum == x)
		{
			cnt++;
			left++;
			right--;
		}
		else if (sum < x)
			left++;
		else
			right--;
	}
	cout << cnt << '\n';
	return 0;
}