#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
using namespace std;

const int MAX = 100000 + 1;

int k, x;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> k;
	stack<long long > s;
	while (k--)
	{
		cin >> x;
		if (x == 0 && !s.empty())
			s.pop();
		else
			s.push(x);
	}
	long long sum = 0;

	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	cout << sum << endl;
	return 0;
}