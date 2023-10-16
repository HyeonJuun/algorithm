#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 10001;

int n, d, p;
int answer;

priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> v;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> d;
		v.push_back({ d, p });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		pq.push(v[i].second);
		if (pq.size() > v[i].first)
			pq.pop();
	}
	while (!pq.empty())
	{
		answer += pq.top();
		pq.pop();
	}
	cout << answer;
	return 0;
}