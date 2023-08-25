#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

map<string, string> mp;
map<string, int> cost;

void dfs(string seller, int money)
{
    if(seller == "center")
        return;
    
    if(money < 1)
    {
        cost[seller] += money;
        return;
    }
    
    cost[seller] += money - floor(money * 0.1);
    dfs(mp[seller], floor(money * 0.1));
    
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    for(int i=0; i<enroll.size(); i++)
    {
        string e = enroll[i];
        string r = referral[i];
        
        if(r == "-")
        {
            mp.insert({e, "center"});
        }
        else
            mp.insert({e, r});
        
        cost[e] = 0;
    }
    for(int i=0; i<seller.size(); i++)
    {
        string s = seller[i];
        int mon = amount[i] * 100;
        
        dfs(s, mon);
    }
    for(int i=0; i<enroll.size();i++)
        answer.push_back(cost[enroll[i]]);
    return answer;
}