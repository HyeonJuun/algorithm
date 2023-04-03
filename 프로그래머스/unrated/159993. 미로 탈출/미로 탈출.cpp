#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

char map[101][101];
int visited[101][101];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int sx, sy, ex, ey, lx, ly;
int w, h;

void bfs(int sx, int sy, int ex, int ey)
{
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x == ex && y == ey)
            return;
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= h || ny >= w || map[nx][ny] == 'X')
                continue;
            if(visited[nx][ny] == 0)
            {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }

        }
    }
}
int solution(vector<string> maps) {
    int answer = 0;
    w = maps[0].size();
    h = maps.size();
    for(int i=0; i<maps.size(); i++)
    {
        for(int j=0; j<maps[i].size(); j++)
        {
            map[i][j] = maps[i][j];
            if(maps[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            else if(maps[i][j] == 'L')
            {
                lx = i;
                ly = j;
            }
            else if(maps[i][j] == 'E')
            {
                ex = i;
                ey = j;
            }
        }
    }
    
    bfs(sx, sy, lx, ly);
    int dist1 = visited[lx][ly];
    bfs(lx, ly, ex, ey);
    int dist2 = visited[ex][ey];
    
    if(dist1 == 0 || dist2 == 0)
        answer = -1;
    else
        answer = dist1 + dist2;
    return answer;
}