#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    map<string, int> mp;
    set<string> n(gems.begin(), gems.end());
    int mn, start = 0, end = 0;
    
    for(int i=0; i<gems.size(); i++)
    {
        mp[gems[i]]++;
        if(mp.size() == n.size())
            break;
        end++;
    }
    
    mn = end - start;
    answer.push_back(start + 1);
    answer.push_back(end + 1);
    
    while(end < gems.size())
    {
        string key = gems[start];
        
        mp[key]--;
        start++;
        
        if(mp[key] == 0)
        {
            end++;
            for(; end < gems.size(); end++)
            {
                mp[gems[end]]++;
                if(key == gems[end])
                    break;
            }
            if(end == gems.size())
                break;
        }
        if(mn > end - start)
        {
            answer[0] = start + 1;
            answer[1] = end + 1;
            mn = end - start;
        }
    }
    return answer;
}