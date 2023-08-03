#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> empties;
vector<vector<pair<int, int>>> puzzles;

bool visited[51][51];
int answer = 0;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;

vector<pair<int, int>> repos(vector<pair<int, int>> pos)
{
    int min_i = N;
    int min_j = N;
    
    for(int i=0; i<pos.size(); i++)
    {
        min_i = min_i > pos[i].first ? pos[i].first : min_i;
        min_j = min_j > pos[i].second ? pos[i].second : min_j;
    }
    
    for(int i=0; i<pos.size(); i++)
    {
        pos[i].first -= min_i;
        pos[i].second -= min_j;
    }
    return pos;
}
vector<pair<int, int>> bfs(vector<vector<int>> &map, int value, int i, int j)
{
    visited[i][j] = true;
    vector<pair<int, int>> v;
    queue<pair<int, int>> q;
    q.push({i, j});
    v.push_back({i, j});
    
    while(!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        
        for(int ind = 0; ind<4; ind++)
        {
            int nx = x + dx[ind];
            int ny = y + dy[ind];
            
            if(nx <0 || ny < 0 || nx >= N || ny >= N)
                continue;
            if(visited[ny][nx] || map[ny][nx] != value)
                continue;
            visited[ny][nx] = true;
            q.push({ny, nx});
            v.push_back({ny, nx});
        }
    }
    return repos(v);
}
void rot(vector<pair<int, int>> &pos)
{
    int row =0;
    for(int i =0; i<pos.size(); i++)
    {
        row = row < pos[i].first ? pos[i].first : row;
    }
    for(int i=0; i<pos.size(); i++)
    {
        int y = pos[i].first;
        int x = pos[i].second;
        
        pos[i].first = x;
        pos[i].second = row - y;
    }
}

void match_puzzle()
{
    vector<bool> puzzle_visited(puzzles.size(), false);
    
    for(auto empty : empties)
    {
        for(int ind =0; ind<puzzles.size(); ind++)
        {
            if(puzzle_visited[ind])
                continue;
            vector<pair<int, int>> puzzle = puzzles[ind];
            if(empty.size() != puzzle.size())
                continue;
            
            bool flag = false;
            
            for(int r = 0; r<4; r++)
            {
                int k=0;
                
                for(int i=0; i<empty.size(); i++)
                {
                    for(int j=0; j<puzzle.size(); j++)
                    {
                        if(empty[i].first == puzzle[j].first &&
                            empty[i].second == puzzle[j].second)
                        {
                            k++;
                            continue;
                        }
                    }
                }
                if(k != empty.size())
                {
                    rot(puzzle);
                    continue;
                }
                answer += empty.size();
                puzzle_visited[ind] = true;
                flag = true;
                break;
            }
            if(flag)
                break;
        }
    }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    N = game_board.size();
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(game_board[i][j] == 0 && !visited[i][j])
                empties.push_back(bfs(game_board, 0, i, j));
        }
    }
    memset(visited, false, sizeof(visited));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(table[i][j] == 1 && !visited[i][j])
                puzzles.push_back(bfs(table, 1, i, j));
        }
    }
    match_puzzle();
    
    return answer;
}