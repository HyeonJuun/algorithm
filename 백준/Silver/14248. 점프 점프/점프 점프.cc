#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <cstring> 

using namespace std;

int n, start, ans = 0;
queue<int> q;
int arr[100001] = { 0, };
bool visited[100001] = { false, };

void bfs(int start)
{
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int c = q.front();
		q.pop();
		if (1 <= c - arr[c] && !visited[c - arr[c]])
		{
			visited[c - arr[c]] = true;
			q.push(c - arr[c]);
		}
		if (c + arr[c] <= n && !visited[c + arr[c]])
		{
			visited[c + arr[c]] = true;
			q.push(c + arr[c]);
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	cin >> start;
	bfs(start);
	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
			ans++;
	}
	cout << ans << endl;
	return 0;
}


