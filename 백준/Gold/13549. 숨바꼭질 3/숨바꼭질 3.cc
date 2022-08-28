#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include<algorithm>
using namespace std;

const int MAX = 100000 +1;


int n, k;

int p[100001]{  };
int w = 0;
int min_w = 1000000;

void bfs()
{
	queue<int> q;
	q.push(n);
	p[n] = 0;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		if (cur == k)
		{
			min_w = p[cur];
			return;
		}
		if (cur * 2 < MAX && p[cur * 2] > p[cur])
		{
			p[cur * 2] = p[cur];
			q.push(cur * 2);
		}
		if (cur + 1 < MAX && p[cur + 1] > p[cur] + 1)
		{
			p[cur + 1] = p[cur] + 1;
			q.push(cur + 1);
		}
		if (cur - 1 >= 0 && p[cur - 1] > p[cur] + 1)
		{
			p[cur - 1] = p[cur] + 1;
			q.push(cur - 1);
		}
	}
}



int main(void)
{
	cin >> n >> k;
	for (int i = 0; i < MAX; i++)
	{
		p[i] = 1000000;
	}

	bfs();
	cout << min_w << endl;

	return 0;

}
