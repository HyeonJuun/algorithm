#include <string>
#include <vector>

using namespace std;

int visited[101][101];// 1~50까지 칸
int answer = 987654321;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void dfs(int startx, int starty, int itemx, int itemy, int cnt)
{
    if(startx == itemx && starty == itemy)
    {
        answer = min(answer, cnt);
        return;
    }
    
    for(int i=0; i<4; i++)
    {
        int nx = startx + dx[i];
        int ny = starty + dy[i];
        
        if(visited[nx][ny] == 7)
        {
            visited[nx][ny] = 0;
            dfs(nx, ny, itemx, itemy, cnt + 1);
            visited[nx][ny] = 7;
        }
    }
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;
    
    for(int i=0;i<rectangle.size();i++){// 모든사각형 칠하기
        for(int a=rectangle[i][0]*2;a<=rectangle[i][2]*2;a++){
            for(int b=rectangle[i][1]*2;b<=rectangle[i][3]*2;b++)
                visited[a][b]=7;
        }
    }
    
    for(int i=0;i<rectangle.size();i++){// 속 파내기
        for(int a=rectangle[i][0]*2+1;a<=rectangle[i][2]*2-1;a++){
            for(int b=rectangle[i][1]*2+1;b<=rectangle[i][3]*2-1;b++)
                visited[a][b]=0;
        }
    }
    visited[characterX][characterY] = 1;
    dfs(characterX, characterY, itemX, itemY, 0);
    
    return answer / 2;
}