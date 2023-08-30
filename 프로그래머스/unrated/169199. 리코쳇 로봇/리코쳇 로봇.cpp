#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 100000;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int dist[110][110];
bool visited[110][110];

int solution(vector<string> board) {
    int answer = 0;
    int x, y, gx, gy;
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].size(); j++)
        {
            if(board[i][j] == 'R')
            {
                x = i;
                y = j;
                
            }
            if(board[i][j] == 'G')
            {
                gx = i;
                gy = j;
            }
        }
    }
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[0].size(); j++)
            dist[i][j] = INF;
    }
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;
    visited[x][y] = true;
    
    while(!q.empty())
    {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++)
        {
            int nx = curx, ny = cury;
            while(true)
            {
                nx += dx[i];
                ny += dy[i];
                
                if(nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size() || board[nx][ny] == 'D')
                {
                    nx -= dx[i];
                    ny -= dy[i];
                    break;
                }
            }
            if(visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            dist[nx][ny] = min(dist[nx][ny], dist[curx][cury] + 1);
            q.push({nx, ny});
        }
    }
    if(dist[gx][gy] == INF)
        answer = -1;
    else
        answer = dist[gx][gy];
    return answer;
}