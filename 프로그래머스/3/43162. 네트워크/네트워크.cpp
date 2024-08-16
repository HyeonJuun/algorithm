#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define MAX 200 + 1

using namespace std;

bool visited[MAX];
vector<int> mp[MAX];

void bfs(int cur)
{
    queue<int> q;
    q.push(cur);
    visited[cur] = true;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i=0; i<mp[cur].size(); i++)
        {
            int nx = mp[cur][i];
            if(!visited[nx])
            {
                q.push(nx);
                visited[nx] = true;
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<computers.size(); i++)
    {
        for(int j=0; j<computers[0].size(); j++)
        {
            if(i == j)
                continue;
            if(computers[i][j] == 1)
            {
                mp[i].push_back(j);
            }
        }
    }
    for(int i=0; i<computers.size(); i++)
    {
        if(!visited[i])
        {
            bfs(i);
            answer++;
        }
    }
    return answer;
}