#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

const int MAX = 1000 + 1;

int r, c, q;
int arr[MAX][MAX];
int prefix[MAX][MAX];
int ans = 0, sum = 0;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c >> q;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + arr[i][j];
		}
	}
	while (q--)
	{
		int r1, c1, r2, c2;
		ans = 0;
		cin >> r1 >> c1 >> r2 >> c2;
		int ans = prefix[r2][c2] - prefix[r1 - 1][c2] - prefix[r2][c1 - 1] + prefix[r1 - 1][c1 - 1];
		ans /= (r2 - r1 + 1) * (c2 - c1 + 1);
		cout << ans << '\n';
	}
	return 0;
}