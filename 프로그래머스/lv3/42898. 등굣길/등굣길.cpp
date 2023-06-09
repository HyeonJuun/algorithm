#include <string>
#include <vector>
#include <iostream>
using namespace std;

int map[110][110];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(int i=0; i<puddles.size(); i++)
    {
        map[puddles[i][1]][puddles[i][0]] = -1;
    }
    map[1][1] = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            
            if(map[i][j] == -1)
                continue;
            
            if(map[i-1][j] != -1)
                map[i][j] = (map[i][j] + map[i-1][j]) % 1000000007;
            if(map[i][j-1] != -1)
                map[i][j] = (map[i][j] + map[i][j-1]) % 1000000007;
        }
    }
    answer = map[n][m];
    return answer;
}