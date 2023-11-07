#include <vector>
#include <algorithm>
#include<iostream>
#include <cstring>
#include <queue>

#define INF 2e9
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int answer = 0, n;
		cin >> n;
        
        int arr[100][100];
        int dist[100][100];
        
        
        memset(arr, 0, sizeof(arr));

        for(int i=0; i<n; i++)
        {
         	for(int j=0; j<n; j++)
                dist[i][j] = INF;
        }
        for(int i=0; i<n; i++)
        {
            string s;
            cin >>s;
         	for(int j=0; j<n; j++)
            {
             	arr[i][j] = s[j] - '0';
            }
        }
        
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 0});
        dist[0][0] = 0;
        
		while(!q.empty())
        {
         	int x = q.front().first.first;
            int y = q.front().first.second;
            int cost = q.front().second;
            q.pop();
            
            if(dist[x][y] != cost)
                continue;
            for(int i=0; i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int ncost = dist[x][y] + arr[nx][ny];
                if(nx < 0 || ny<0 || nx >=n || ny >=n)
                    continue;
                
                if(ncost < dist[nx][ny])
                {
					q.push({{nx, ny}, ncost});
                    dist[nx][ny] = ncost;
                }
            }
        }
        
        cout << "#" << test_case << " " << dist[n-1][n-1] << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}