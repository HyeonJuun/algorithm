#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;

const int MAX = 100000 + 1;




int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<>> pq;
	vector <pair<int, int>> lec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> lec[i].first >> lec[i].second;
	}
	sort(lec.begin(), lec.end());
	pq.push(lec[0].second);
	for (int i = 1; i < n; i++)
	{
		int start = lec[i].first;
		int end = lec[i].second;
		if (start >= pq.top())
		{
			pq.pop();
			pq.push(end);
		}
		else
		{
			pq.push(end);
		}
	}
	cout << pq.size() << endl;
	return 0;
}