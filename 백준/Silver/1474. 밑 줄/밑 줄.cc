#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	int n, m = 0;
	int word_len =0;
	string st;

	cin >> n >> m;
	vector<string> std;

	for (int i = 0; i < n; i++)
	{
		cin >> st;
		word_len += st.size();
		std.push_back(st);
	}
	int min_size = (m - word_len) / (n - 1);
	int leftOver = (m - word_len) - (min_size * (n - 1));

	string s = std[0];
	int leftWord = std.size() - 1;
	for (int i = 1; i < std.size(); i++)
	{
		if (std[i][0] >= 'A' && std[i][0] <= 'Z')
		{
			if (leftWord == leftOver)
			{
				for (int j = 0; j < min_size + 1; j++) {
					s += '_';
				}
				s += std[i];
				leftOver--;
				leftWord--;
			}
			else
			{
				for (int j = 0; j < min_size; j++)
				{
					s += '_';
				}
				s += std[i];
				leftWord--;
			}
		}
		else
		{
			if (leftOver > 0)
			{
				for (int j = 0; j < min_size + 1; j++) {
					s += '_';
				}
				s += std[i];
				leftOver--;
				leftWord--;
			}
			else
			{
				for (int j = 0; j < min_size; j++)
				{
					s += '_';
				}
				s += std[i];
				leftWord--;
			}
		}
	}
	cout << s;

	return 0;
}
