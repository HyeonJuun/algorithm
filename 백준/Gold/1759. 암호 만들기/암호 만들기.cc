#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1000002;

int L, C, ans = 0;
vector<char> arr;
vector<char> sel_arr;

bool check()
{
	int moum = 0;
	for (int i = 0; i < L; i++)
	{
		if (sel_arr[i] == 'a' ||
			sel_arr[i] == 'i' ||
			sel_arr[i] == 'e' ||
			sel_arr[i] == 'o' ||
			sel_arr[i] == 'u')
		{
			moum++;
		}
	}
	if (moum >= 1 && L - moum >= 2)
		return true;
	else
		return false;
}

void dfs(int x)
{
	if ((int)sel_arr.size() == L)
	{
		if (check())
		{
			for (int i = 0; i < L; i++)
			{
				cout << sel_arr[i];
			}
			cout << '\n';
		}
	}
	for (int i = x; i < C; i++)
	{
		sel_arr.push_back(arr[i]);
		dfs(i + 1);
		sel_arr.pop_back();
	}

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		char c;
		cin >> c;
		arr.push_back(c);
	}
	sort(arr.begin(), arr.end());
	dfs(0);
	return 0;
}