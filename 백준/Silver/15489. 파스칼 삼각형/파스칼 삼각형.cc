#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 30 + 1;

int paskal[MAX][MAX];

int R, C, W, ans=0;

int main() {
	cin >> R >> C >> W;
	for (int i = 1; i < MAX; i++)
		for (int j = 1; j <= i; j++)
		{
			if (j == 1 || j == i) paskal[i][j] = 1;
			else paskal[i][j] = paskal[i - 1][j - 1] + paskal[i - 1][j];
		}
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j <= i; j++)
			ans += paskal[R + i][C + j];
	}
	cout << ans << endl;
	return 0;
}