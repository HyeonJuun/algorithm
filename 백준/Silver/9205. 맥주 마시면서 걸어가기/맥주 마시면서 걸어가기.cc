#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 101;

vector<pair<int, int> > cvs = { {0,0}, };
bool visited[MAX] = { false, };
pair<int, int> rock_f;
int start_x, start_y;
int t, n, m, a, b;
void bfs()
{
	queue<pair<int, int> > q;
	q.push(make_pair(start_y, start_x));
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (abs(y - rock_f.first) + abs(x - rock_f.second) <= 1000)
		{
			cout << "happy";
			return;
		}
		else
		{
			for (int i = 0; i < cvs.size(); i++)
			{
				if (abs(y - cvs[i].first) + abs(x - cvs[i].second) <= 1000)
				{
					if (!visited[i])
					{
						visited[i] = true;
						q.push(make_pair(cvs[i].first, cvs[i].second));
					}
				}
			}
		}
	}
	cout << "sad";
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		cvs = vector<pair<int, int> >(n, { 0, 0 });
		memset(visited, false, sizeof(visited));
		cin >> start_y >> start_x;
		for (int i = 0; i < n; i++)
			cin >> cvs[i].first >> cvs[i].second;
		cin >> rock_f.first >> rock_f.second;
		bfs();
		cout << endl;
	}
	return 0;
}
