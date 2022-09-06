#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100000 + 1;

int a, b, c;
int map[21][21][21];

int solve(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return solve(20, 20, 20);
	if (map[a][b][c])
		return map[a][b][c];
	if (a < b && b < c)
	{
		map[a][b][c] = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);
		return map[a][b][c];
	}
	else
	{
		map[a][b][c] = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
		return map[a][b][c];
	}
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	while (true)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
		{
			break;
		}
		cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << endl;
	}
	return 0;
}