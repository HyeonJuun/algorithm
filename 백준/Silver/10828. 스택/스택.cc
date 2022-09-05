#include <iostream>
#include <algorithm>
#include<stack>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 50 + 1;

int n;
string str;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	stack<int> s;
	while (n--)
	{
		cin >> str;
		if (str == "push")
		{
			int x; cin >> x;
			s.push(x);
		}
		else if (str == "pop")
		{
			if (s.empty())
				cout << -1 << endl;
			else
			{
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (str == "top")
		{
			if (s.empty())
				cout << -1 << endl;
			else
				cout << s.top() << endl;
		}
		else if (str == "empty")
		{
			cout << s.empty() << endl;
		}
		else
			cout << s.size() << endl;
	}
	return 0;
}