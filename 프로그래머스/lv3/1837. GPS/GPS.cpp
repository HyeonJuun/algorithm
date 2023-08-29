#include <vector>

using namespace std;

const int INF = 2e9;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    
    vector<int> node[210];
    vector<vector<int>> dp(k, vector<int>(n+1, INF));

    for(int i=0; i<edge_list.size(); i++)
    {
        node[edge_list[i][0]].push_back(edge_list[i][1]);
        node[edge_list[i][1]].push_back(edge_list[i][0]);
    }
    
    dp[0][gps_log[0]] = 0;
    
    for(int i=1; i<k; i++)
    {
        for(int cur = 1; cur <= n; cur++)
        {
            if(dp[i - 1][cur] == INF)
                continue;
            
            for(int j=0; j<node[cur].size(); j++)
            {
                int nx = node[cur][j];
                int alpha = 0;
                
                if(gps_log[i] != nx)
                    alpha++;
                
                dp[i][nx] = min(dp[i][nx], dp[i-1][cur] + alpha);
            }
        }
    }
    if(dp[k-1][gps_log[k-1]] < INF)
        return dp[k-1][gps_log[k-1]];
    return -1;
}