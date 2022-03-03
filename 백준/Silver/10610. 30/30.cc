#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	vector<int> num;
	string str;
	int sum = 0;
	bool checkz = false;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		num.push_back(str[i] - '0');
	}
	sort(num.begin(), num.end(), greater<>());
	if (num.back() != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < num.size(); i++)
	{
		sum += num[i];
	}
	if (sum % 3 == 0)
	{
		for (int i = 0; i < num.size(); i++)
			cout << num[i];
	}
	else
	{
		cout << -1 << endl;
	}
	return 0;
}