#include <string>
#include <vector>

using namespace std;

const int INF = 987654321;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int last = problems.size() - 1;
    int min_time;
    int alp_req = -1;
    int cop_req = -1;
    
    for(int i=0; i<=last; i++)
    {
        if(alp_req < problems[i][0])
            alp_req = problems[i][0];
        
        if(cop_req < problems[i][1])
            cop_req = problems[i][1];
    }
    if(alp_req <= alp && cop_req <= cop)
        return 0;
    
    vector<vector<int>> dp(alp_req+1, vector<int>(cop_req+1, INF));
    
    if(alp > alp_req)
        alp = alp_req;
    if(cop > cop_req)
        cop = cop_req;
    
    dp[alp][cop] = 0;
    
    for(int i = alp; i<=alp_req; i++)
    {
        for(int j=cop; j<=cop_req; j++)
        {
            if(j + 1 <= cop_req)
                dp[i][j + 1] = min(dp[i][j+1], dp[i][j] + 1);
            if(i+1 <= alp_req)
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
            
            for(int k=0; k<=last; k++)
            {
                if(i >= problems[k][0] && j >= problems[k][1])
                {
                    dp[min(i + problems[k][2], alp_req)][min(j + problems[k][3], cop_req)] = min(dp[min(i + problems[k][2], alp_req)][min(j + problems[k][3], cop_req)], dp[i][j] + problems[k][4]);
                }
            }
            
        }
    }
    return answer = dp[alp_req][cop_req];
}