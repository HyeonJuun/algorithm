#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 51;

int arr[9];
int select_arr[9];
bool visited[9];
int n, m;

void dfs(int k, int dep)
{
	if (dep == m)
	{
		for (int i = 0; i < m; i++)
			cout << select_arr[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = k; i <= n; i++)
	{
		if (visited[i] == true)
			continue;
		select_arr[dep] = arr[i];
		visited[i] = true;
		dfs(i, dep + 1);
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		arr[i] = i;

	dfs(1, 0);
	return 0;
}