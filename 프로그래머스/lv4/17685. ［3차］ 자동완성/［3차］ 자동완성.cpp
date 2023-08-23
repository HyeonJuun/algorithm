#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> words) {
    int answer = 1, pre = 0;
    
    sort(words.begin(), words.end());
    
    string preWord = words[0];

    for(int i=1; i<words.size(); i++)
    {
        int idx = 0;
        
        for(; idx<words[i].size(); idx++)
        {
            if(idx >= preWord.size())
            {
                answer += preWord.size() - pre - 1;
                answer += idx + 1;
                break;
            }
            
            if(words[i][idx] != preWord[idx])
            {
                if(idx > pre)
                    answer += idx - pre;
                answer += idx + 1;
                break;
            }
        }
        pre = idx;
        preWord = words[i];
    } 
    return answer;
}