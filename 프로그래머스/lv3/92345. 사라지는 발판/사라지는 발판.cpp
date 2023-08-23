#include <string>
#include <vector>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int n, m;
bool visited[5][5];
vector<vector<int>> map;

bool ck(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= m;
}
int solve(vector<int> aPoint, vector<int> bPoint)
{
    if(visited[aPoint[0]][aPoint[1]])
        return 0;
    
    int res = 0;
    
    for(int i=0; i<4; i++)
    {
        int nx = aPoint[0] + dx[i];
        int ny = aPoint[1] + dy[i];
        
        if(ck(nx, ny) || visited[nx][ny] || !map[nx][ny])
            continue;
        
        visited[aPoint[0]][aPoint[1]] = 1;
        int val = solve(bPoint, {nx, ny}) + 1;
        visited[aPoint[0]][aPoint[1]] = 0;
        
        if(res % 2 == 0 && val % 2 == 1)
            res = val;
        else if(res % 2 == 0 && val % 2 == 0)
            res = max(res, val);
        else if(res % 2 == 1 && val % 2 == 1)
            res = min(res, val);
    }
    
    return res;
}
int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    
    n = board.size();
    m = board[0].size();
    map = board;
    
    return solve(aloc, bloc);
}