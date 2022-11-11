#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<queue>
using namespace std;

const int MAX = 8 + 1;

int n, m, last;
int arr[MAX];
int sel_arr[MAX];
int visited[MAX];

void dfs(int idx, int dep)
{
	if (dep == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << sel_arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	int last = 0;
	for (int i = idx; i < n; i++)
	{
		if (visited[i] == 0 && arr[i] != last)
		{
			sel_arr[dep] = arr[i];
			last = sel_arr[dep];
			visited[i] = 1;
			dfs(i, dep + 1);
			visited[i] = 0;
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	dfs(0, 0);
	return 0;
}
