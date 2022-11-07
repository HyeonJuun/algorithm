#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1000 + 1;

int t, n, x;

vector<int> arr[MAX];
bool check[MAX];

void dfs(int num)
{
	check[num] = true;
	for (int i = 0; i < arr[num].size(); i++)
	{
		int next = arr[num][i];
		if (!check[next])
			dfs(next);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			arr[i].clear();
			check[i] = false;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			arr[i].push_back(x);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!check[i])
			{
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}