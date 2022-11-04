#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int MAX = 8 + 1;

int arr[MAX];
int sel_arr[MAX];
int visited[MAX];

int n, m;

void dfs(int dep)
{
	if (dep == m)
	{
		for (int i = 0; i < m; i++)
			cout << sel_arr[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == true)
			continue;
		visited[i] = true;
		sel_arr[dep] = arr[i];
		dfs(dep + 1);
		visited[i] = false;
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
	dfs(0);
	return 0;
}