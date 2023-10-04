#include <string>
#include <vector>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int visited[101][101];
int answer = 2e9;

void dfs(int curX, int curY, int itemX, int itemY, int cnt)
{
    if(curX == itemX && curY == itemY)
    {
        answer = min(cnt, answer);
        return;
    }
    
    for(int i=0; i<4; i++)
    {
        int nx = curX + dx[i];
        int ny = curY + dy[i];
        
        if(visited[nx][ny] == 2)
        {
            visited[nx][ny] = 0;
            dfs(nx, ny, itemX, itemY, cnt + 1);
            visited[nx][ny] = 2;
        }
    }
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    for(int i=0; i<rectangle.size(); i++)
    {
        for(int x = rectangle[i][0] *2; x <=rectangle[i][2] * 2;x++)
        {
            for(int y = rectangle[i][1] * 2; y<= rectangle[i][3] * 2; y++)
            {
                visited[x][y] = 2;
            }
        }
    }
    
    for(int i=0; i<rectangle.size(); i++)
    {
        for(int x = rectangle[i][0] * 2 + 1; x <= rectangle[i][2] * 2 - 1; x++)
        {
            for(int y = rectangle[i][1] * 2 + 1; y<= rectangle[i][3] * 2 - 1; y++)
            {
                visited[x][y] = 0;
            }
        }
    }
    
    visited[characterX][characterY] = 1;
    dfs(characterX, characterY, itemX, itemY, 0);
        
    
    return answer / 2;
}