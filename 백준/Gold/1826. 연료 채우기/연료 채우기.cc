#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 1000001;

int n, l, p;
int info[MAX];
int answer;

priority_queue<int> pq;
bool flag;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		info[a] = b;
	}
	cin >> l >> p;
	
	for (int i = 1; i < l; i++)
	{
		p--;
		if (info[i] != 0)
			pq.push(info[i]);

		if (!p)
		{
			if (pq.empty())
			{
				cout << -1;
				flag = true;
				break;
			}
			else
			{
				p += pq.top();
				answer++;
				pq.pop();
			}
		}
	}
	if(!flag)
		cout << answer;
	return 0;
}