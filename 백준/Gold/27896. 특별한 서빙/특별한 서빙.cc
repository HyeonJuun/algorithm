#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 200001;

int st[MAX];

int n, m;

priority_queue<int> pq;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;

	int answer = 0;
	int num = 0;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		pq.push(x);
		num += x;

		while (num >= m)
		{
			answer++;
			num -= pq.top() * 2;
			pq.pop();
		}
	}
	cout << answer;
	return 0;
}