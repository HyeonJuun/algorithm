#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n, m;
int prv[10];
int answer = 2e9, count;

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {1, -1, 0, 0, 0};
void calc(int x, int y, int count, vector<vector<int>> &clock)
{
    for(int i=0; i<5; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= clock.size() || ny >= clock[0].size())
            continue;
        
        clock[nx][ny] = (clock[nx][ny] + count) % 4;
    }
    
}
void dfs(int j, vector<vector<int>>& v)
{
    if(j == m)
    {
        int res = 0;
        vector<vector<int>> va = v;
        for(int i=0; i<m; i++)
        {
            calc(0, i, prv[i], va);
            res += prv[i];
        }
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int rm = (4 - va[i-1][j]) % 4;
                calc(i, j, rm, va);
                res += rm;
            }
        }
        bool flag = true;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(va[i][j] != 0)
                    flag = false;
            }
        }
        if(flag)
            answer = min(answer, res);
        return;
    }
    for(int i=0; i<4; i++)
    {
        prv[j] = i;
        dfs(j + 1, v);
    }
}
int solution(vector<vector<int>> clockHands) {
    n = clockHands.size();
    m = clockHands[0].size();
    
    dfs(0, clockHands);
    return answer;
}