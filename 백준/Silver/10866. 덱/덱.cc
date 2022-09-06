#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include<deque>
using namespace std;

const int MAX = 100000 + 1;

int k, x;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> k;
	deque<int> dq;

	while (k--)
	{
		string str;
		cin >> str;
		if (str == "push_front")
		{
			cin >> x;
			dq.push_front(x);
		}
		if (str == "push_back")
		{
			cin >> x;
			dq.push_back(x);
		}
		if (str == "pop_front")
		{
			if (dq.empty())
				cout << -1 << endl;
			else
			{
				x = dq.front();
				dq.pop_front();
				cout << x << endl;
			}
		}
		if (str == "pop_back")
		{
			if (dq.empty())
				cout << -1 << endl;
			else
			{
				x = dq.back();
				dq.pop_back();
				cout << x << endl;
			}
		}
		if (str == "size")
			cout << dq.size() << endl;
		if (str == "empty")
		{
			if (dq.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		if (str == "front")
		{
			if (dq.empty())
				cout << -1 << endl;
			else
				cout << dq.front() << endl;
		}
		if (str == "back")
		{
			if (dq.empty())
				cout << -1 << endl;
			else
				cout << dq.back() << endl;
		}
	}
	
	return 0;
}