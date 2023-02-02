#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cmath>

using namespace std;

const int MAX = 100000 + 10;

string str;
stack<char> st;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			cout << str[i];
		else
		{
			if (str[i] == '(')
				st.push(str[i]);
			else if (str[i] == '*' || str[i] == '/')
			{
				while (!st.empty() && (st.top() == '*' || st.top() == '/'))
				{
					cout << st.top();
					st.pop();
				}
				st.push(str[i]);
			}
			else if (str[i] == '+' || str[i] == '-')
			{
				while (!st.empty() && st.top() != '(')
				{
					cout << st.top();
					st.pop();
				}
				st.push(str[i]);
			}
			else if (str[i] == ')')
			{
				while (!st.empty() && st.top() != '(')
				{
					cout << st.top();
					st.pop();
				}
				st.pop();
			}
		}
	}
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
	return 0;
}