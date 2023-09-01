#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i=0; i<progresses.size(); i++)
    {
        if((100 - progresses[i]) % speeds[i] == 0)
            q.push((100 - progresses[i]) / speeds[i]);
        else
            q.push((100 - progresses[i]) / speeds[i] + 1);
    }
    
    while(!q.empty())
    {
        int cnt = 1;
        int cur = q.front();
        q.pop();
        
        while(!q.empty() && q.front() <= cur)
        {
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);
    }
    
    return answer;
}