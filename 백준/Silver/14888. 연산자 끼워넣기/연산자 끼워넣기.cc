#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<queue>
#include<set>

using namespace std;

const int MAX = 11 + 1;

int n;
int operands[MAX];
int operators[4];

int ansMin = 1000000001;
int ansMax = -1000000001;

void solve(int res, int idx)
{
	if (idx == n)
	{
		if (res > ansMax)
			ansMax = res;
		if (res < ansMin)
			ansMin = res;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (operators[i] > 0)
		{
			operators[i]--;
			if (i == 0)
				solve(res + operands[idx], idx + 1);
			else if (i == 1)
				solve(res - operands[idx], idx + 1);
			else if (i == 2)
				solve(res * operands[idx], idx + 1);
			else if (i == 3)
				solve(res / operands[idx], idx + 1);

			operators[i]++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> operands[i];
	for (int i = 0; i < 4; i++)
		cin >> operators[i];
	solve(operands[0], 1);
	cout << ansMax << '\n' << ansMin << '\n';
	return 0;
}