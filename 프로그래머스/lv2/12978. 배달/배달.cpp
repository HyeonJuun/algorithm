#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> v[55];
vector<int> dist;


void solve(int n)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty())
    {
        int cost = - pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        for(int i=0; i<v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int ncost = v[cur][i].second;
            
            if(dist[next] > cost + ncost)
            {
                dist[next] = cost + ncost;
                pq.push({-dist[next], next});
            }
        }
    }
    
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    dist.resize(N+1, 987654321);
    for(int i=0; i<road.size(); i++)
    {
        int a = road[i][0];
        int b = road[i][1];
        int d = road[i][2];
        
        v[a].push_back({b, d});
        v[b].push_back({a, d});
    }
    solve(N);
    for(int i=1; i<=N;i++)
        if(dist[i] <= K)
            answer++;
    return answer;
}