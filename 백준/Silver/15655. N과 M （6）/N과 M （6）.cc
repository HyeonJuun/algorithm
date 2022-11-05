#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const long long MAX = 8 + 1;

int n, m;

int arr[MAX];
int sel_arr[MAX];
int visited[MAX];

void dfs(int num, int dep)
{
	if (dep == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << sel_arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = num; i < n; i++)
	{
		if (visited[i] == 1)
			continue;
		visited[i] = true;
		sel_arr[dep] = arr[i];
		dfs(i, dep + 1);
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	dfs(0, 0);
	return 0;
}