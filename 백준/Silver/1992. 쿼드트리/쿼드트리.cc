#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<string>
#include <cstring>
#include<queue>
#include<deque>

using namespace std;

const int MAX = 64 + 1;

int map[MAX][MAX];
bool visited[MAX][MAX];

int n;

void solve(int x, int y, int size)
{
	int c = map[x][y];
	if (size == 1)
	{
		cout << map[x][y];
		return;
	}
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (c != map[i][j])
			{
				cout << "(";
				solve(x, y, size / 2);
				solve(x, y + size / 2, size / 2);
				solve(x + size / 2, y, size / 2);
				solve(x + size / 2, y + size / 2, size / 2);
				cout << ")";
				return;
			}
		}
	}
	if (c == 1)
		cout << 1;
	else if (c == 0)
		cout << 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = s[j] - '0';
		}
	}
	solve(0, 0, n);
	return 0;
}