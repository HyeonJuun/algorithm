#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

const int MAX = 1000 + 1;

string s;
int ans = 0;
int alpha[27];

bool ck(string s)
{
	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == s[i + 1])
			return false;
	}
	return true;
}
void dfs(int idx, string str)
{
	if (idx == s.length())
	{
		ans++;
		return;
	}
	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] == 0)
			continue;
		if (idx != 0 && str[str.length() - 1] == (char)('a' + i))
			continue;
		alpha[i]--;
		dfs(idx + 1, str + (char)('a' + i));
		alpha[i]++;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		alpha[s[i] - 'a']++;
	}
	dfs(0, "");
	cout << ans << '\n';
	return 0;
}