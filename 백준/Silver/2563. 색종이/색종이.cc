#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 100 + 1;

int n;
int map[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		for (int a = y; a < y + 10; a++)
		{
			for (int b = x; b < x + 10; b++)
			{
				if (!map[a][b])
				{
					ans++;
					map[a][b] = 1;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}