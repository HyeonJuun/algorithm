#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int mx = -1, N;
vector<vector<int>> mp;
vector<int> dist;

void bfs(int x)
{
    queue<pair<int, int>> q;
    vector<bool> visited(N+1, false);
    q.push({1, 0});
    visited[1] = true;
    
    while(!q.empty())
    {
        int cur = q.front().first;
        int count = q.front().second;
        q.pop();
        
        if(cur == x)
        {
            dist[x] = count;
            if(count > mx)
                mx = count;
            break;
            
        }
        for(int i=0; i<mp[cur].size(); i++)
        {
            int nx = mp[cur][i];
            
            if(!visited[nx])
            {
                visited[nx] = true;
                q.push({nx, count + 1});
            }
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    N = n;
    mp.resize(n+1);    
    dist.resize(n+1);
    
    for(int i=0; i<edge.size(); i++)
    {
        mp[edge[i][0]].push_back(edge[i][1]);
        mp[edge[i][1]].push_back(edge[i][0]);
    }
    
    for(int i=2; i<=n; i++)
    {
        bfs(i);
    }
    for(int i=2; i<=n; i++)
    {
        if(dist[i] == mx)
        {
            answer++;
        }
    }
    return answer;
}