#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool visited[51][51];
long t_map[2501][51][51];

vector<int> answer(2, INT32_MAX);
vector<vector<int>> map;
int M, N, S;

vector<int> solution(int m, int n, int s, vector<vector<int>> time_map) {

    M = m, N = n, S = s;
    map = time_map;
    
    for(int k = 0; k< 2501; k++)
    {
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
                t_map[k][i][j] = INT32_MAX;
        }
    }
    
    
    
    queue<pair<pair<int, int>, int>> q;
    
    q.push({{0, 0}, 0});
    t_map[0][0][0] = 0;
    
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        
        if(t_map[dist][x][y] > s || dist > n * m)
            continue;
        
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && time_map[nx][ny] != -1)
            {
                if(t_map[dist + 1][nx][ny] > t_map[dist][x][y] + time_map[nx][ny])
                {
                    q.push({{nx, ny}, dist + 1});
                    t_map[dist + 1][nx][ny] = t_map[dist][x][y] + time_map[nx][ny];                    
                }
            }
        }
    }
    
    for(int i=0; i<= n* m; i++)
    {
        if(t_map[i][m-1][n-1] > s)
            continue;
        
        answer[0] = i;
        answer[1] = t_map[i][m-1][n-1];
        break;
    }
    return answer;
}