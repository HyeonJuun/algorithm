#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

const int MAX = 8 + 1;

int n, m, last;

int arr[MAX];
int sel_arr[MAX];


void dfs(int dep)
{
	if (dep == m)
	{
		for (int i = 0; i < m; i++)
			cout << sel_arr[i] << " ";
		cout << '\n';
		return;
	}
	int last = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != last)
		{
			sel_arr[dep] = arr[i];
			last = sel_arr[dep];
			dfs(dep + 1);
		}

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
	dfs(0);

	return 0;
}