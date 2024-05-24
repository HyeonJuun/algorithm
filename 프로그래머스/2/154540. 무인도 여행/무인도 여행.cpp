#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int map[101][101];
bool visited[101][101];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int w, h;

int solve(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int res = map[x][y];
    
    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= h || ny >= w || map[nx][ny] == 0) 
                continue;
            if(!visited[nx][ny])
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
                res += map[nx][ny];
            }
        }
    }
    return res;
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
    
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(map[i][j] != 0 && !visited[i][j]) {
                int res = solve(i, j);
                answer.push_back(res);
            }
        }
    }
    if(answer.size() == 0)
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
    return answer;
}