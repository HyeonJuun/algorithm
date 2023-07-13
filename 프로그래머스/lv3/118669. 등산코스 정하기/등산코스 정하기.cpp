#include <string>
#include <vector>
#include <queue>

using namespace std;

// 노드[x] 가 2 이면 정상이다
int nodes[50010];

int intensity[50010];
vector<vector<pair<int,int>>> mp(50010);
priority_queue<pair<int,int>> pq;

int ans_intensity = 1e9, ans_summit = 1e9;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    for(int i=1; i<=n; i++)
        intensity[i] = 1e8;
    
    for(auto s : summits)
        nodes[s] = 2;
    
    for(auto p : paths)
    {
        mp[p[0]].push_back({p[1], p[2]});
        mp[p[1]].push_back({p[0], p[2]});
    }
    for(auto g : gates)
    {
        intensity[g] = -1;
        pq.push({g, 0});
    }
    
    while(!pq.empty())
    {
        int cur = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        
        if(cost > ans_intensity)
            continue;
        
        if(nodes[cur] == 2)
        {
            if(cost < ans_intensity)
            {
                ans_intensity = cost;
                ans_summit = cur;
            }
            else if(cost == ans_intensity && cur < ans_summit)
                ans_summit = cur;
            continue;
        }
        
        for(int i = 0; i<mp[cur].size(); i++)
        {
            int nx = mp[cur][i].first;
            int nx_cost = mp[cur][i].second;
            
            if(intensity[nx] > max(cost, nx_cost))
            {
                intensity[nx] = max(cost, nx_cost);
                pq.push({nx, intensity[nx]});
            }
        }
    }
    answer.push_back(ans_summit);
    answer.push_back(ans_intensity);
    return answer;
}