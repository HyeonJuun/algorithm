#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int alphabet[26] = { 0, };

	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		alphabet[str[i] - 'A']++;
	}
	int mid_index = -1;
	int err = 0;

	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > 0) {
			if (alphabet[i] % 2 == 1) {
				mid_index = i;
				alphabet[i]--;
				err++;
			}
		}
	}
	if (err >= 2)
	{
		cout << "I'm Sorry Hansoo" << endl;
	}
	else
	{
		string ans = "";
		string temp = "";
		for (int i = 0; i < 26; i++)
		{
			if (alphabet[i] > 0)
			{
				for (int j = 0; j < alphabet[i] / 2; j++)
				{
					ans += i + 'A';
				}
			}
		}
		temp = ans;
		reverse(temp.begin(), temp.end());
		if (mid_index != -1)
		{
			ans += mid_index + 'A';
		}
		ans += temp;
		cout << ans << endl;
	}

	return 0;
}
