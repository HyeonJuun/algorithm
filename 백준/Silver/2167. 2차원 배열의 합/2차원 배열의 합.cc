#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<string>
#include <cstring>
#include<queue>

using namespace std;

const int MAX = 300 + 1;

int map[MAX][MAX];
int n, m, k;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	}
	cin >> k;
	while (k--)
	{
		int i, j, x, y;
		int sum = 0;
		cin >> i >> j >> x >> y;
		for (int a = i; a <= x; a++)
		{
			for (int b = j; b <= y; b++)
			{
				sum += map[a][b];
			}
		}
		cout << sum << '\n';
	}
	return 0;
}