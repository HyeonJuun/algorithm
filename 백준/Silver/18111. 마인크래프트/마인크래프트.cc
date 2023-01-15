#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;

const int MAX = 500 + 1;

int n, m, b;
int map[MAX][MAX];
int leastTime = 0x7f7f7f7f;
int mxheight;
int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	for(int h = 0; h<= 256; h++)
	{
		int build = 0;
		int remove = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int height = map[i][j] - h;
				if (height > 0)
					remove += height;
				else if (height < 0)
					build -= height;
			}
		}
		if (remove + b >= build)
		{
			int time = remove * 2 + build;
			if (leastTime >= time)
			{
				leastTime = time;
				mxheight = h;
			}
		}
	}
	cout << leastTime << " " << mxheight << '\n';
	return 0;
}