#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

const int INF = INT32_MAX;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
    
int answer = INF;
int n;
bool visited[30][30];
int map[30][30];
int dist[30][30];

void dfs(int x, int y, int dir, int cost)
{
    // x, y, dir, cost 담아놓기
    if(cost > dist[x][y])
        return;
    if(cost < dist[x][y])
        dist[x][y] = cost;

    if(x == n-1 && y == n-1)
    {
        answer = answer < cost ? answer : cost;
        return;
    }
    
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!visited[nx][ny] && nx >= 0 && ny >= 0 && nx < n && ny < n && !map[nx][ny])
        {
            visited[nx][ny] = true;
            if(dir == i || (x == 0 && y == 0))
                dfs(nx, ny, i, cost + 100);
            else
                dfs(nx, ny, i, cost + 600);
            visited[nx][ny] = false;
        }
        
    }
}
int solution(vector<vector<int>> board) {
    
    n = board.size();
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].size(); j++)
        {
            map[i][j] = board[i][j];
            dist[i][j] = INF;
        }
    }
    visited[0][0] = true;
    dfs(0, 0, 0, 0);
    return answer;
}