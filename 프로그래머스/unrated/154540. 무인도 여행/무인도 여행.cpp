#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int map[101][101];
bool visited[101][101];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int w, h;

int bfs(int x, int y)
{
    int cnt = map[x][y];
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    
    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= h || ny >=w || map[nx][ny] == 0)
                continue;
            
            if(!visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
                cnt += map[nx][ny];
            }
        }
        
    }
    return cnt;
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    w = maps[0].size();
    h = maps.size();
    for(int i=0; i<maps.size(); i++)
    {
        for(int j=0; j<maps[i].size(); j++)
        {
            if(maps[i][j] != 'X')
                map[i][j] = maps[i][j] - '0';
            else
                maps[i][j] = 0;
        }
    }
    
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(!visited[i][j] && map[i][j] != 0)
            {
                int count = bfs(i, j);
                answer.push_back(count);
            }
        }
    }
    if(answer.size() == 0)
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
    return answer;
}