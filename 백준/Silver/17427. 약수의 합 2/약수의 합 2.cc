#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

const int MAX = 10000000 + 1;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	unsigned long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += (n / i) * i;
	}
	cout << ans << '\n';
	return 0;
}