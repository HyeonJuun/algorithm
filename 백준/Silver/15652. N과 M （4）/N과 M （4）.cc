#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 9;

int arr[MAX];
int sel_arr[MAX];
int visited[MAX];

int n, m;

void dfs(int num, int dep)
{
	if (dep == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << sel_arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = num; i <= n; i++)
	{
		visited[i] = 1;
		sel_arr[dep] = arr[i];
		dfs(i, dep + 1);
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}

	dfs(1, 0);


	return 0;
}