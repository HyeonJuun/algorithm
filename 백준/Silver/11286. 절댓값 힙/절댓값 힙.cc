#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;

const int MAX = 100000 + 1;


int n, k;
struct compare {
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	}
};
int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, compare> pq;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if (pq.empty())
				cout << 0 << "\n";
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
		{
				pq.push(x);
		}
	}
	return 0;
}