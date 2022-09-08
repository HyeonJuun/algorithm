#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include<deque>
#include<queue>

using namespace std;

const int MAX = 300000 + 1;

int n, k;
int bag[MAX];
pair<int, int> jewelry[MAX];

//Max Heap 사용
priority_queue<int> pq;


int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> jewelry[i].first >> jewelry[i].second;
	}
	for (int i = 0; i < k; i++)
		cin >> bag[i];
	sort(jewelry, jewelry + n);
	sort(bag, bag + k);
	long long ans = 0;
	int idx = 0;
	for (int i = 0; i < k; i++)
	{
		while (idx < n && jewelry[idx].first <= bag[i])
			pq.push(jewelry[idx++].second);

		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans << endl;
	return 0;
}