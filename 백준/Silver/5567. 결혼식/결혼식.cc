#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

const int MAX = 500 + 1;

int n, m, cnt = 0;

vector<int> v[MAX];
bool visited[MAX];

void solve(int num)
{

	for (int i = 0; i < v[num].size(); i++)
	{
		int next = v[num][i];
		visited[next] = true;
	}

	if (num == 1)
	{
		for (int i = 0; i < v[num].size(); i++)
		{
			int next = v[num][i];
			solve(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	solve(1);
	for (int i = 2; i <= n; i++)
	{
		if (visited[i])
			cnt++;
	}
	cout << cnt << '\n';
	return 0;
}