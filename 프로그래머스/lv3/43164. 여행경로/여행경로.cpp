#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> answer;
bool visited[100000001];
bool flag;
int cnt =0 ;

void dfs(string cur, vector<vector<string>> ticket)
{
    if(cnt == (int)ticket.size())
        flag = true;
    
    answer.push_back(cur);
    for(int i=0; i<ticket.size(); i++)
    {
        if(!visited[i] && ticket[i][0] == cur)
        {
            visited[i] = true;
            cnt++;
            dfs(ticket[i][1], ticket);
        
            if(!flag)
            {
                answer.pop_back();
                visited[i] = false;
            }
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets);
    return answer;
}