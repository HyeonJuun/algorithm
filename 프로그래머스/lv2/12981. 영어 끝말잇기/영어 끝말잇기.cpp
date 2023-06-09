#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <stack>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    int cnt = 1;
    int num = 1;
    map<string, int> w_map;
    stack<char> ck;
    int len = words[0].length();
    ck.push(words[0][len - 1]);
    w_map[words[0]] = 1;
    
    for(int i=1; i<words.size(); i++)
    {
        len = words[i].length();
        if(words[i][0] != ck.top() || w_map[words[i]] == 1)
        {
            answer.push_back(num + 1);
            answer.push_back(i / n + 1);
            break;
        }
        else
        {
            w_map[words[i]] = 1;
            ck.pop();
            ck.push(words[i][len-1]);
        }
        num = (num+1) % n;
    }
    if(answer.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}