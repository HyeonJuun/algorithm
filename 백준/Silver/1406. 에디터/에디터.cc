#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

const int MAX = 500000 + 1;




int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string str;
	stack<char> left_stack;
	stack<char> right_stack;
	cin >> str;
	
	for (int i = 0; i < str.length(); i++)
		left_stack.push(str[i]);

	int num; cin >> num;

	while (num--)
	{
		char input;	cin >> input;

		if (input == 'P')
		{
			char c;	cin >> c;
			left_stack.push(c);
		}
		else if (input == 'L')
		{
			if (left_stack.empty())
				continue;
			else
			{
				right_stack.push(left_stack.top());
				left_stack.pop();
			}
		}
		else if (input == 'B')
		{
			if (left_stack.empty())
				continue;
			else
				left_stack.pop();
		}
		else if (input == 'D')
		{
			if (right_stack.empty())
				continue;
			else 
			{
				left_stack.push(right_stack.top());
				right_stack.pop();
			}
		}

	}
	while (!left_stack.empty())
	{
		right_stack.push(left_stack.top());
		left_stack.pop();
	}
	while (!right_stack.empty())
	{
		cout << right_stack.top();
		right_stack.pop();
	}
	return 0;
}