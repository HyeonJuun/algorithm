#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include<algorithm>
using namespace std;

const int MAX = 50 + 1;


int n, x, y, min = MAX;

// 친구 나타내기
vector<int> v[MAX];


// first : 몇번 후보 , second : 점수
vector<pair<int, int>>  ans;


void bfs()
{
	for (int i = 1; i <= n; i++)
	{
		if (v[i].size() == 0)
			continue;
		queue<pair<int, int>> q;
		int visited[MAX] = { 0, };
		int total = 0;
		q.push(make_pair(i, 0));
		while (!q.empty())
		{
			int f = q.front().first;
			int level = q.front().second;
			visited[f] = true;
			q.pop();
			total = max(total, level);

			for (int j = 0; j < v[f].size(); j++)
			{
				if (visited[v[f][j]] == true)
					continue;
				visited[v[f][j]] = true;
				q.push(make_pair(v[f][j], level + 1));
			}
		}
		ans.push_back(make_pair(total, i));

	}
}



int main(void)
{
	cin >> n;
	while (true)
	{
		cin >> x >> y;
		if (x == -1 && y == -1)
			break;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs();
	sort(ans.begin(), ans.end());

	int ansCnt = 0;
	int ansFriend = ans[0].first;
	vector<int> A;
	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[0].first == ans[i].first)
		{
			ansCnt++;
			A.push_back(ans[i].second);
		}
	}
	cout << ansFriend << " " << ansCnt << endl;
	for (int i = 0; i < A.size(); i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;

}
