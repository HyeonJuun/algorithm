#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	int ans =0;
	string num;
	bool isMinus = false;
	for (int i = 0; i <= str.size(); i++)
	{
		if (str[i] == '-' || str[i] == '+' || i == str.size())
		{
			if (isMinus)
			{
				ans -= stoi(num);
				num = "";
			}
			else
			{
				ans += stoi(num);
				num = "";

			}
		}
		else
		{
			num += str[i];
		}
		if (str[i] == '-')
		{
			isMinus = true;
		}
	}
	cout << ans << endl;
	return 0;
}
