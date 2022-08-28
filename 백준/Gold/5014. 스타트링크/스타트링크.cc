#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include<algorithm>
using namespace std;

const int MAX = 1000000 + 1;


int F, S, G, U, D;

vector<int> dx;
int path[MAX] = { 0, };
bool visited[MAX] = { false, };


void bfs(int start)
{
	queue<int> q;
	visited[start] = true;
	q.push(start);
	while (!q.empty())
	{
		start = q.front();
		q.pop();

		for (int i = 0; i < 2; i++)
		{
			int ns = start + dx[i];

			if (0 < ns && ns <= F)
			{
				if (!visited[ns])
				{
					visited[ns] = true;
					q.push(ns);
					path[ns] = path[start] + 1;
				}
			}
		}
	}
}



int main(void)
{
	cin >> F >> S >> G >> U >> D;
	dx.push_back(U);
	dx.push_back(D * (-1));
	bfs(S);

	if (visited[G])
		cout << path[G] << endl;
	else
		cout << "use the stairs"  << endl;
	return 0;

}
