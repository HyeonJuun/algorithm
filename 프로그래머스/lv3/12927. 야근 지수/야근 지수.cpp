#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> q(works.begin(), works.end());
    
    for(int i=0; i<n; i++)
    {
        if(q.top() > 0)
        {
            int x = q.top();
            q.pop();
            q.push(x -1);
        }
    }
    while(!q.empty())
    {
        answer += q.top() * q.top();
        q.pop();
    }
    return answer;
}