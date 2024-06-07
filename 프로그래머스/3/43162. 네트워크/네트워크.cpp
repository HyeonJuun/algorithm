#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool visited[210];
vector<int> mp[210];

void bfs(int num)
{
    queue<int> q;
    q.push(num);
    visited[num] = true;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int i=0; i<mp[cur].size(); i++)
        {
            int nxt = mp[cur][i];
            if(!visited[nxt])
            {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<computers.size(); i++)
    {
        for(int j=0; j<computers[i].size(); j++)
        {
            if(i == j)
                continue;
            if(computers[i][j] == 1) 
                mp[i].push_back(j);
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