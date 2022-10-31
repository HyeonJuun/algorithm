#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 10001;

int n, k, ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	vector<int> coin;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		coin.push_back(x);
	}
	for (int i = coin.size() - 1; i >= 0; i--)
	{
		if (k == 0)
			break;
		if (k >= coin[i])
		{
			ans += (k / coin[i]);
			k = k % coin[i];
		}
	}
	cout << ans << '\n';
	return 0;
}