#include <string>
#include <vector>

using namespace std;

int prefix[1010][1010];
int n, m;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    n = board.size(), m = board[0].size();
    
    for(auto sk : skill)
    {
        int degree = sk[5];
        if(sk[0] == 1)
            degree = -degree;
        
        prefix[sk[1]][sk[2]] += degree;
        prefix[sk[3] + 1][sk[4] + 1] += degree;
        prefix[sk[1]][sk[4] + 1] -= degree;
        prefix[sk[3] + 1][sk[2]] -= degree;
    }
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<m ; j++)
            prefix[i][j+1] += prefix[i][j];
    }
    
    for(int j=0; j<m+1; j++)
    {
        for(int i=0; i<n; i++)
        {
            prefix[i+1][j] += prefix[i][j];
        }
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            if(board[i][j] + prefix[i][j] > 0)
                answer++;
    }
    return answer;
}