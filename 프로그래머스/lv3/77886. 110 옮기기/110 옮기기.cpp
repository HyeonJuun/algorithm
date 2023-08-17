#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int find_zero(string s)
{
    for(int i = s.length() - 1; i>= 0; i--)
        if(s[i] == '0')
            return i;
return -1;
    
}
vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for(int i=0; i < s.size(); i++)
    {
        string str = "";
        int cnt = 0;
        for(int j =0 ; j<s[i].length(); j++)
        {
            str += s[i][j];
            if (str.length() >= 3)
            {
                if (str.substr(str.length() - 3, 3) == "110")
                {
                    cnt++;
                    str.erase(str.length() - 3, str.length());
                }
            }
        }
        int fzero = find_zero(str);
        if(fzero == -1)
        {
            string res = "";
            for(int j=0; j<cnt; j++)
            {
                res += "110";
            }
            res += str;
            answer.push_back(res);
        }
        else
        {
            string res = "";
                
            for(int j =0; j<str.length(); j++)
            {
                if(j == fzero)
                {
                    res += str[j];
                    while(cnt--)
                        res += "110";
                }
                else
                {
                    res += str[j];
                }
            }
            answer.push_back(res);
        }
    }
    
    return answer;
}