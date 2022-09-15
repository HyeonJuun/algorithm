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
	string str;
	cin >> str;

	stack<double> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			s.push(v[str[i] - 'A']);
		}
		else
		{
			if (!s.empty())
			{
				double a = s.top();
				s.pop();
				double b = s.top();
				s.pop();
				switch (str[i])
				{
				case '+':
					s.push(a + b);
					break;
				case '-':
					s.push(b - a);
					break;
				case'*':
					s.push(a * b);
					break;
				case'/':
					s.push(b / a);
					break;
				default:
					break;
				}
			}
		}
	}
	double ans = s.top();
	printf("%.2f\n", ans);
	return 0;
}