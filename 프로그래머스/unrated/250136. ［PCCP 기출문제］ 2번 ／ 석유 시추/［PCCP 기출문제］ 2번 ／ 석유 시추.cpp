#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

int width, height, cnt, idx = 2;
vector<vector<int>> lands;
bool visited[510][510];
int sum[125000];
bool ck[125000];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void bfs(int x, int y, int idx)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    cnt++;
    visited[x][y] = true;
    lands[x][y] = idx;
    
    while(!q.empty())
    {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            
            if(nx<0 || ny <0 || nx>=height || ny >=width || lands[nx][ny] == 0)
                continue;
            
            if(!visited[nx][ny])
            {
                q.push({nx, ny});
                lands[nx][ny] = idx;
                cnt++;
                visited[nx][ny] = true;
            }
        }
    }
    sum[idx] = cnt;
}
int solution(vector<vector<int>> land) {
    int answer = -1;
    lands = land;
    width = land[0].size(), height = land.size();
    
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            if(lands[j][i] == 1 && !visited[j][i])
            {
                cnt = 0;
                bfs(j,i, idx++);
            }
        }
    }
    for(int i=0; i<width; i++)
    {
        int mx = 0;
        for(int j=2; j<idx; j++)
        {
            ck[j] = false;
        }
        for(int j=0; j<height; j++)
        {
            int x = lands[j][i];
            if(x != 0 && ck[x] == false)
            {
                mx += sum[x];
                ck[x] = true;
            }
        }
        if(mx > answer)
            answer = mx;
    }
    return answer;
}