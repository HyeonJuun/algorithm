#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int b_cnt = 0, w_cnt = 0;
int arr[128][128];

void solve(int y, int x, int size)
{
	int check = arr[y][x];

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (check == 0 && arr[i][j] == 1)
				check = 2;
			if (check == 1 && arr[i][j] == 0)
				check = 2;

			if (check == 2)
			{
				solve(y, x, size / 2);
				solve(y, x + size / 2, size / 2);
				solve(y + size / 2, x, size / 2);
				solve(y + size / 2, x + size / 2, size / 2);
				return;
			}
		}
	}
	if (check == 0)
		w_cnt++;
	else
		b_cnt++;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	solve(0, 0, n);
	cout << w_cnt << '\n' << b_cnt << '\n';
	return 0;
}