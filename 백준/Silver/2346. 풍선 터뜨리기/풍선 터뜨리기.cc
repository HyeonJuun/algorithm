#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<queue>
#include<deque>

using namespace std;

const int MAX = 1000 + 1;

int n;
deque<pair<int, int>> dq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;	cin >> x;
		dq.push_back({ i, x });
	}
	while (!dq.empty())
	{
		int cur = dq.front().first;
		int num = dq.front().second;
		dq.pop_front();
		cout << cur << " ";

		if (num > 0)
		{
			num--;
			while (!num == 0)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				num--;
			}
		}
		else
		{
			while (!num == 0)
			{
				dq.push_front(dq.back());
				dq.pop_back();
				num++;
			}
		}
	}
	return 0;
}