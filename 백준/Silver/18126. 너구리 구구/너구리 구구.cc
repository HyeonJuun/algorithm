#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

vector<pair<int, long long> > v[5010];

long long dfs(int x, int p)
{
	long long ans = 0;
	for (int i = 0; i < v[x].size(); i++)
	{
		if (v[x][i].first == p) continue;
		ans = max(ans, dfs(v[x][i].first, x) + v[x][i].second);
	}
	return ans;
}

int main()
{
	int n, a, b, c;
	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	cout << dfs(1, -1);

	return 0;
}