#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> mp;
int N;
int bfs(int start, int end)
{
    queue<pair<int, int>> q;
    vector<bool> visited(N+1, false);
    q.push({start, 0});
    visited[start] = true;
    
    while(!q.empty())
    {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if(cur == end)
        {
            return dist;
        }
        
        for(int i=0; i<mp[cur].size(); i++)
        {
            int nx = mp[cur][i];
            
            if(!visited[nx])
            {
                q.push({nx, dist + 1});
                visited[nx] = true;
            }
        }
    }
    return -1;
}
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    N = n;
    mp.resize(n+1);
    for(int i=0; i<roads.size(); i++)
    {
        mp[roads[i][0]].push_back(roads[i][1]);
        mp[roads[i][1]].push_back(roads[i][0]);
    }
    
    for(int i=0; i<sources.size(); i++)
    {
        int ans = bfs(sources[i], destination);
        answer.push_back(ans);
    }
    return answer;
}