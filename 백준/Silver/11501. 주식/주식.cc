#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include<deque>
#include<queue>

using namespace std;

const int MAX = 10000 + 1;

int t, n, x;
int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--)
	{
		// 날짜를 거꾸로 생각하면 풀기
		cin >> n;
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			v.push_back(x);
		}
		long long ans = 0;
		int max_value = -1;
		for (int i = n - 1; i >= 0; i--)
		{
			max_value = max(max_value, v[i]);
			ans += max_value - v[i];
		}
		cout << ans << endl;
	}
	return 0;
}