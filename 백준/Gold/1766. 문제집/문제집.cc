#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 32001;

int n, m;
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> v[MAX];
int preSolve[MAX];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		preSolve[b]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (preSolve[i] == 0)
			pq.push(i);
	}

	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();

		cout << cur << " ";

		for (int i = 0; i < v[cur].size(); i++)
		{
			int nxt = v[cur][i];
			preSolve[nxt]--;

			if (preSolve[nxt] == 0)
				pq.push(nxt);
		}
	}
	return 0;
}