#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int answer = 987654321;

vector<int> card;
bool ck_card[7];

vector<vector<int>> b;
int rr, cc;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int bfs(int card)
{
    bool visited[4][4] = {0, };
    queue<pair<pair<int, int>, int>> q;
    
    q.push({{rr, cc}, 0});
    visited[rr][cc] = true;
    
    while(!q.empty())
    {
        int curR = q.front().first.first;
        int curC = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        
        if(b[curR][curC] == card)
        {
            b[curR][curC] = 0;
            rr = curR;
            cc = curC;
            return dist + 1;
        }
        
        for(int i=0; i<4; i++)
        {
            int nr = curR + dr[i];
            int nc = curC + dc[i];
    
            if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4)
                continue;
            
            if(!visited[nr][nc])
            {
                q.push({{nr, nc}, dist + 1});
                visited[nr][nc] = true;
            }
            
        }
        
        for(int i=0; i<4; i++)
        {
            int nr = curR, nc = curC;
            
            while(nr + dr[i] >= 0 && nr + dr[i] < 4 && nc + dc[i] >= 0 && nc + dc[i] < 4)
            {
                nr += dr[i];
                nc += dc[i];
                
                if(b[nr][nc])
                    break;
            }
            if(!visited[nr][nc])
            {
                visited[nr][nc] = true;
                q.push({{nr, nc}, dist + 1});
            }
        }
    }
}
int solution(vector<vector<int>> board, int r, int c) {
    
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board.size(); j++)
        {
            if(board[i][j] != 0)
            {
                ck_card[board[i][j]] = 1;
            }
        }
    }
    for(int i=0; i<7; i++)
    {
        if(ck_card[i])
            card.push_back(i);
    }
    sort(card.begin(), card.end());
    
    do
    {
        b = board;
        rr = r;
        cc = c;
        
        int tmp = 0;
        for(int i=0; i<card.size(); i++)
        {
            tmp += bfs(card[i]);
            tmp += bfs(card[i]);
        }
        answer = min(answer, tmp);
    }while(next_permutation(card.begin(), card.end()));
    return answer;
}