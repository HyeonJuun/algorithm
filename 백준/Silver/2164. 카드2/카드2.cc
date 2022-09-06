#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include<deque>
#include<queue>

using namespace std;

const int MAX = 500000 + 1;

int n, x;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++)
		q.push(i);
	while (q.size() != 1)
	{
		q.pop();
		x = q.front();
		q.pop();
		q.push(x);
	}
	cout << q.front() << endl;
	return 0;
}