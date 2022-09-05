#include <iostream>
#include <algorithm>
#include<stack>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 50 + 1;

int t;
string str;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--)
	{
		cin >> str;
		stack<char> s;
		string ans = "YES";
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '(')
				s.push(str[i]);
			else if (str[i] == ')' && !s.empty() && s.top() == '(')
				s.pop();
			else
			{
				ans = "NO";
				break;
			}
		}
		if (!s.empty())
			ans = "NO";
		cout << ans << endl;
	}
	return 0;
}