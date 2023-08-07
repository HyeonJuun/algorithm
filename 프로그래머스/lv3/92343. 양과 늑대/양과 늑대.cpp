#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int answer = 1;
vector<vector<int>> map;
vector<int> animInfo;
vector<int> nextNode;
queue<int> q;

void dfs(int curNode, int wolf, int sheep, vector<int> nextNode, vector<int> info, vector<vector<int>> map)
{
    int anim = animInfo[curNode];
    if(anim)
        wolf++;
    else
        sheep++;
    
    if(wolf >= sheep)
        return;
    
    answer = max(answer, sheep);
    
    for(int i=0; i<nextNode.size(); i++)
    {
        vector<int> next = nextNode;
        next.erase(next.begin() + i);
        for(int j=0; j<map[nextNode[i]].size(); j++)
        {
            next.push_back(map[nextNode[i]][j]);
        }
        dfs(nextNode[i], wolf, sheep, next, info, map);
    }
    
}
int solution(vector<int> info, vector<vector<int>> edges) {
    
    animInfo = info;
    
    map.resize(info.size());
    for(int i=0; i<edges.size(); i++)
        map[edges[i][0]].push_back(edges[i][1]);
    
    for(int i=0; i<map[0].size(); i++)
       nextNode.push_back(map[0][i]);
    
    dfs(0, 0, 0, nextNode, info, map);
    return answer;
}