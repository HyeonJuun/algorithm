#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer;
int par[110];

int GetParent(int num)
{
    if(par[num] == num)
        return num;
    return par[num] = GetParent(par[num]);
}
bool cmp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}
int solution(int n, vector<vector<int>> costs) {
    
    for(int i=0; i<n; i++)
        par[i] = i;
    
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i=0; i<costs.size(); i++)
    {
        int start = GetParent(costs[i][0]);
        int end = GetParent(costs[i][1]);
        int cost = costs[i][2];
        
        if(start != end)
        {
            answer += cost;
            par[end] = start;
        }
    }
    return answer;
}