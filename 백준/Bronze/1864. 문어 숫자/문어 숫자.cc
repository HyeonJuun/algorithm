#include<iostream>
#include<string>
#include <cmath>

using namespace std;

int main()
{
	string str;
	while (1)
	{
		cin >> str;
		int ans = 0;
		if (str == "#")
		{
			break;
		}
		for (int i = 0; i < str.length(); i++)
		{
			switch (str[i])
			{
			case '-':
				break;
			case '\\':
				ans += pow(8, str.length() - (i + 1));
				break;
			case '(':
				ans += 2 * pow(8, str.length() - (i + 1));
				break;
			case '@':
				ans += 3 * pow(8, str.length() - (i + 1));
				break;
			case '?':
				ans += 4 * pow(8, str.length() - (i + 1));
				break;
			case '>':
				ans += 5 * pow(8, str.length() - (i + 1));
				break;
			case '&':
				ans += 6 * pow(8, str.length() - (i + 1));
				break;
			case '%':
				ans += 7 * pow(8, str.length() - (i + 1));
				break;
			case '/':
				ans += -1 * pow(8, str.length() - (i + 1));
				break;
			default:
				break;
			}
		}

		cout << ans << endl;
	}
	return 0;
}