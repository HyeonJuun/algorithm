#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(int i=0; i<targets.size(); i++)
    {
        answer.push_back(0);
        for(int j=0; j<targets[i].size();j++)
        {
            char t = targets[i][j];
            bool flag = false;
            
            int bnum = 987654321;
            for(int k=0; k<keymap.size(); k++)
            {
                for(int l =0; l<keymap[k].size(); l++)
                {
                    if(t == keymap[k][l])
                    {
                        bnum = min(bnum, l + 1);
                        flag = true;
                        break;
                    }
                }
            }
            if(!flag)
            {
                answer[i] = -1;
                break;
            }
            else
                answer[i] += bnum;
        }
    }
    
    return answer;
}