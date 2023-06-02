#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<bool> visited(210, false);
vector<int> mp[210];

void bfs(int num)
{
    queue<int> q;
    
    q.push(num);
    visited[num] = true;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        visited[cur] = true;
        for(int i=0; i<mp[cur].size(); i++)
        {
            if(!visited[mp[cur][i]])
            {
                q.push(mp[cur][i]);
                visited[mp[cur][i]] = true;
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i == j)
                continue;
            if(computers[i][j] == 1)
            {
                mp[i].push_back(j);
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            bfs(i);
            cout << endl;
            answer++;            
        }
    }
    return answer;
}