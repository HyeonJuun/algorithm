#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<string>
#include <cstring>
#include<queue>
#include<deque>

using namespace std;

const int MAX = 1000000 + 1;


int n;
long long arr[MAX];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	queue<long long> q;
	for (int i = 1; i <= 9; i++)
	{
		q.push(i);
		arr[i] = i;
	}
	if (0 <= n && n <= 10)
	{
		cout << n - 1<< '\n';
	}
	else
	{
		int ind = 10;
		while (ind <= n && !q.empty())
		{
			long long num = q.front();
			q.pop();

			int last = num % 10;
			for (int i = 0; i < last; i++)
			{
				q.push(num * 10 + i);
				arr[ind++] = num * 10 + i;
			}
		}
		if (ind >= n && arr[n - 1] != 0)
			cout << arr[n - 1] << '\n';
		else
			cout << -1;
	}
	
	return 0;
}