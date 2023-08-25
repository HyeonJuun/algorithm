#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> res(n+1, vector<int>(n+1, -1));
    
    for(int i=0; i<results.size(); i++)
        res[results[i][0]][results[i][1]] = 1;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=n; k++)
            {
                if(res[j][i] == 1 && res[i][k] == 1)
                    res[j][k] = 1;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        int cnt = 0;
        for(int j=1; j<=n; j++)
        {
            if(res[i][j] == 1 || res[j][i] == 1)
                cnt++;
        }
        if(cnt == n-1)
            answer++;
    }
    return answer;
}