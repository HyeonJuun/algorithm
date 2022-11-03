#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 2188;

int arr[MAX][MAX];
int ans[3] = { 0, 0, 0 };
int n;
int sum = 0;

void solve(int x, int y, int size)
{
	int tmp = arr[y][x];
	for (int i = y; i < y + size ; i++)
	{
		for (int j = x; j < x + size ; j++)
		{
			if (tmp != arr[i][j])
			{
				solve(x, y, size / 3);
				solve(x + size / 3, y, size / 3);
				solve(x + size * 2 / 3, y, size / 3);
				solve(x, y + size / 3, size / 3);
				solve(x + size / 3, y + size / 3, size / 3);
				solve(x + size * 2 / 3, y + size / 3, size / 3);
				solve(x, y + size * 2 / 3, size / 3);
				solve(x + size / 3, y + size * 2 / 3, size / 3);
				solve(x + size * 2 / 3, y + size * 2 / 3, size / 3);
				return;
			}
		}
	}
	ans[arr[y][x] + 1]++;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	solve(0, 0, n);
	cout << ans[0] << '\n' << ans[1] << '\n' << ans[2] << '\n';
	return 0;
}