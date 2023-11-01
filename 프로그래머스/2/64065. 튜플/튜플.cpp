#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}
vector<int> solution(string s) {
    vector<int> answer;
    
    string tmp;
    map<int, int> mp;
    
    for (int i = 1; i < s.length() - 1; i++){
      if (s[i] != '{' && s[i] != '}' && s[i] != ',') {
        tmp += s[i];
        if (s[i+1] != ',' && s[i+1] != '}') continue;
        mp[stoi(tmp)]++;
      }
      tmp = "";
    }
    
    vector<pair<int, int>> vmp(mp.begin(), mp.end());
    sort(vmp.begin(), vmp.end(), cmp);
    
    for(auto ans : vmp)
    {
        answer.push_back(ans.first);
    }
    return answer;
}