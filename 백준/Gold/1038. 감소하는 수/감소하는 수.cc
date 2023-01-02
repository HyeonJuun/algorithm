#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 10000010 + 1;

int n;
long long arr[MAX];

void solve()
{
	queue <long long> q;
	for (int i = 1; i <= 9; i++)
	{
		q.push(i);
		arr[i] = i;
	}
	if (0 <= n && n <= 10)
	{
		cout << n << '\n';
		return;
	}
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
	if (ind >= n && arr[n] != 0)
		cout << arr[n] << '\n';
	else
		cout << -1 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	solve();

	return 0;
}