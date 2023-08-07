#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int answer = 0;
vector<string> uid;
vector<string> bid;
set<string> s;

bool visited[10];

void dfs(int ind)
{
    if(ind == bid.size())
    {
        string str = "";
        for(int i=0; i<uid.size(); i++)
            if(visited[i])
                str += (i + '0');
        
        s.insert(str);
        return;
    }
    
    for(int i = 0; i<uid.size(); i++)
    {
        bool flag = true;
        if(visited[i])
            continue;
        if(bid[ind].length() != uid[i].length())
            continue;
            for(int j=0;j<uid[ind].length(); j++)
            {
                if(bid[ind][j] == '*')
                    continue;
                if(bid[ind][j] != uid[i][j])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                visited[i] = true;
                dfs(ind + 1);
                visited[i] = false;
            }
        
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    uid = user_id;
    bid = banned_id;
    
    dfs(0);
    return s.size();
}