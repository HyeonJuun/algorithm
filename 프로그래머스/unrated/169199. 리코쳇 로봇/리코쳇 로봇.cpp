#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 100000;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool visited[110][110];
int depth[110][110];

int solution(vector<string> board) {
    int answer = 0;
    int x, y;
    int gx, gy;
    int row = board.size();
    int col = board[0].size();
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
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
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            depth[i][j] = INF;
    }
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    depth[x][y] = 0;
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++)
        {
            int nx = x;
            int ny = y;
            while(true)
            {
                nx += dx[i];
                ny += dy[i];
                if(nx < 0 || ny < 0 || ny >= col || nx >= row)
                {
                    ny -= dy[i];
                    nx -= dx[i];
                    break;
                }   
                if(board[nx][ny] == 'D')
                {
                    ny -= dy[i];
                    nx -= dx[i];
                    break;
                }   
            }
            
            if(visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            depth[nx][ny] = min(depth[nx][ny], depth[x][y] + 1);
            q.push({nx, ny});
        }

    }
    if(depth[gx][gy] == INF)
        answer = -1;
    else
        answer = depth[gx][gy];
    return answer;
}