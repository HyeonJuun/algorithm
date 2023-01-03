#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<string>
#include <cstring>
#include<queue>
#include<deque>

using namespace std;

const int MAX = 100 + 1;





int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, int>> v;
	for (int i = 0; i < 3; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end());
	int d;
	vector<double> dist;
	d = pow((v[1].second - v[0].second), 2) + pow(v[1].first - v[0].first, 2);
	dist.push_back(d);
	d = pow((v[2].second - v[1].second), 2) + pow(v[2].first - v[1].first, 2);
	dist.push_back(d);
	d = pow((v[2].second - v[0].second), 2) + pow(v[2].first - v[0].first, 2);
	dist.push_back(d);

	sort(dist.begin(), dist.end());
	if ((v[0].first * v[1].second + v[1].first * v[2].second + v[2].first *v[0].second) - (v[1].first *v[0].second + v[2].first *v[1].second + v[0].first *v[2].second) != 0)
	{
		if (dist[0] == dist[1] && dist[1] == dist[2])
			cout << "JungTriangle";
		else if (dist[0] == dist[1] || dist[1] == dist[2])
		{
			if (dist[0] + dist[1] == dist[2])
				cout << "Jikkak2Triangle";
			else if (dist[0] + dist[1] < dist[2])
				cout << "Dunkak2Triangle";
			else
				cout << "Yeahkak2Triangle";
		}
		else if (dist[0] != dist[1] && dist[1] != dist[2])
		{
			if (dist[0] + dist[1] == dist[2])
				cout << "JikkakTriangle";
			else if (dist[0] + dist[1] < dist[2])
				cout << "DunkakTriangle";
			else
				cout << "YeahkakTriangle";
		}
	}
	else
		cout << "X";
	return 0;
}