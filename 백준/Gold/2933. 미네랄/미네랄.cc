#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int d_r[4] = { 1,-1,0,0 };
int d_c[4] = { 0,0,1,-1 };

int r, c;
int n;
char map[101][101];
int visited[101][101];

int gravity(int row, int col, int clu)
{
	for (int a = row + 1; a < r; a++)
	{
		if (map[a][col] == 'x')
		{
			if (visited[a][col] == clu)
				return 1000;
			else
			{
				return a - (row+1);
			}
		}
	}
	return r - (row + 1);

}


void check_map()
{
	int cnt = 1;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if ((map[i][j] == 'x') && (visited[i][j] == 0))
			{
				//이게 땅까지 쭉 연결되어 있는지 확인필요
				// 어케 확인하냐, 한번이라도 바닥 즉 r에 접근했으면 true로 바꿈
				bool is_connet = false;
				vector<pair<int, int> > cluster;
				cluster.push_back(make_pair(i, j));
				visited[i][j] = cnt;
				queue<pair<int, int> > q;
				q.push(make_pair(i, j));
				while (!q.empty())
				{
					int rr = q.front().first;
					int cc = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int new_r = rr + d_r[k];
						int new_c = cc + d_c[k];
						if (new_r == r)
							is_connet = true;
						if (new_r < 0 || new_c < 0 || new_r >= r || new_c >= c)
							continue;
						if (visited[new_r][new_c] != 0)
							continue;
						if (map[new_r][new_c] == '.')
							continue;
						visited[new_r][new_c] = cnt;
						cluster.push_back(make_pair(new_r, new_c));
						q.push(make_pair(new_r, new_c));
					}
				}
				// 두개의 클러스터가 동시에 떨어지는 경우는 없다!
				// 하나 뭉텅이 다 떨궜으면 return
				if (is_connet == false)
				{
					// 떨구기 시작 모양 그대로 유지하고, 지금 cnt 처리되어있는놈들을 전부 떨구기
					// 최소 수직 거리구하기
					int min_length = 1000;
					for (int k = 0; k < cluster.size(); k++)
					{
						int rrr = cluster[k].first;
						int ccc = cluster[k].second;

						min_length =  min(min_length, gravity(rrr, ccc, cnt));
					}

					//수직거리 만큼 떨구기
					for (int a = r - 1; a >= 0; a--)
					{
						for (int b = 0; b < c; b++)
						{
							if (visited[a][b] == cnt)
							{
								map[a + min_length][b] = map[a][b];
								map[a][b] = '.';
								visited[a][b] = 0;
							}
						}
					}
					return;
				}
				cluster.clear();


				cnt++;
			}
		}
	}
	
}



int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		string tmp1;
		cin >> tmp1;
		for (int j = 0; j < c; j++)
		{
			map[i][j] = tmp1[j];
		}

	}
	cin >> n;
	for (int a = 0; a < n; a++)
	{
		int tmp;
		cin >> tmp;
		//홀수면 왼쪽, 짝수면 오른쪽
		// 1) 부셔지는게 있나 찾기
		// 있으면 부셔
		if (a % 2 == 0)
		{
			for (int i = 0; i < c; i++)
			{
				if (map[r - tmp][i] == 'x')
				{
					map[r - tmp][i] = '.';
					break;
				}
			}
		}
		else
		{
			for (int i =c-1; i >= 0; i--)
			{
				if (map[r - tmp][i] == 'x')
				{
					map[r - tmp][i] = '.';
					break;
				}
			}
		}

		// 2) 떠있는 클러스터 있나 확인
		check_map();

	}


	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	return 0;
}