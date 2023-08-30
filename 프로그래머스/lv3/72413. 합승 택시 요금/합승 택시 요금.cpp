#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 987654321;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    vector<vector<int>> dist(n + 1, vector<int>(n+1, INF));
    long long answer = INF;
    for(int i=0; i<fares.size(); i++)
    {
        dist[fares[i][0]][fares[i][1]] = fares[i][2];
        dist[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for(int i=1; i<=n; i++)
        dist[i][i] = 0;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i == j)
                continue;
            
            for(int k=1; k<=n; k++)
            {
                if(dist[j][i] + dist[i][k] < dist[j][k])
                    dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }
    
    for(int i=1; i<=n; i++)
    {            
        if(answer > dist[s][i] + dist[i][a] + dist[i][b])
            answer = dist[s][i] + dist[i][a] + dist[i][b];        
    }
    return answer;
}