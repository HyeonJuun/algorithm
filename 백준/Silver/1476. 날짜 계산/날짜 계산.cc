#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1000 + 1;
const int INF = 987654321;

int e, s, m;
int year = 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> e >> s >> m;

	while (true)
	{
		if ((year - e) % 15 == 0 && (year - s) % 28 == 0 && (year - m) % 19 == 0)
		{
			cout << year << '\n';
			break;
		}
		else
			year++;
	} 
	return 0;
}