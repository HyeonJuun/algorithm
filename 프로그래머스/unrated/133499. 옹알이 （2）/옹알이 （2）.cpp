#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    map<string, bool> mp;
    
    mp["aya"] = true;
    mp["ye"] = true;
    mp["woo"] = true;
    mp["ma"] = true;
    
    for(int i=0; i<babbling.size();i++)
    {
        string tmp = "", prevword = "";
        bool flag = true;
        for(int j=0; j<babbling[i].length(); j++)
        {
            if(tmp.length() > 3)
            {
                flag = false;
                break;
            }
            else
            {
                tmp += babbling[i][j];
                if(mp[tmp] != false && tmp != prevword)
                {
                    prevword = tmp;
                    tmp = "";
                }
            }
        }
        
        if(flag && tmp == "")
           answer++; 
    }
    
    return answer;
}