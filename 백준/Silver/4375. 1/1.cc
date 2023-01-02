#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 100000000 + 1;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (cin >> n)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans = ans * 10 + 1;
			ans %= n;
			if (ans == 0)
			{
				cout << i << '\n';
				break;
			}
		}
	}
	return 0;
}