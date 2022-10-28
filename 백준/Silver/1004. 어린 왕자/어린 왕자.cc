#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;	cin >> t;

	while (t--)
	{
		int x1, y1, x2, y2;	cin >> x1 >> y1 >> x2 >> y2;
		int n;	cin >> n;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			int x, y, r;	cin >> x >> y >> r;
			if ((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) < r * r)
			{
				if ((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y) > r * r)
					cnt++;
			}
			if ((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) > r * r)
			{
				if ((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y) < r * r)
					cnt++;
			}
		}
		cout << cnt << '\n';
	}
	
	return 0;
}