#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 200010;

int t, n, x;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while (t--)
	{
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		long long answer = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			pq.push(x);
		}

		while (!pq.empty())
		{
			if (pq.size() == 1)
				break;
			long long x = pq.top();
			pq.pop();
			long long y = pq.top();
			pq.pop();
			
			pq.push(x + y);
			answer += x + y;
		}
		cout << answer << endl;
	}

	
	return 0;
}