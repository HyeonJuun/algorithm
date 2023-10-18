#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 200010;

int n;
long long answer;

vector<pair<int, int>> v;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	int cup, dead;
	for (int i = 0; i < n; i++)
	{
		cin >> dead >> cup;
		v.push_back({ dead, cup });
	}
	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++)
	{
		if (pq.size() < v[i].first)
		{
			pq.push(v[i].second);
		}
		else
		{
			if (pq.top() < v[i].second)
			{
				pq.pop();
				pq.push(v[i].second);
			}
		}
	}
	while (!pq.empty())
	{
		answer += pq.top();
		pq.pop();
	}
	cout << answer;
	return 0;
}