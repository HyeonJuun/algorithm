#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<string>
#include <cstring>
#include<queue>

using namespace std;

const int MAX = 10 + 1;

int k;

char arr[MAX];
bool visited[MAX];
string str = "";
string min_ans = "9999999999", max_ans = "-1";

void dfs(int prev, int cur)
{
	if (cur == k + 1)
	{
		min_ans = min(min_ans, str);
		max_ans = max(max_ans, str);
		return;
	}
	if (arr[cur - 1] == '>')
	{
		for (int i = 0; i < prev; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				str += (char)(i + '0');
				dfs(i, cur + 1);
				visited[i] = false;
				str.erase(cur, 1);
			}
		}
	}
	else if (arr[cur - 1] == '<')
	{
		for (int i = prev + 1; i <= 9; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				str += char(i + '0');
				dfs(i, cur + 1);
				visited[i] = false;
				str.erase(cur, 1);
			}
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> arr[i];
	for (int i = 0; i <= 9; i++)
	{
		visited[i] = true;
		str += (char)(i + '0');
		dfs(i, 1);
		visited[i] = false;
		str.erase(0, 1);
	}
	cout << max_ans << '\n' << min_ans;
	return 0;
}