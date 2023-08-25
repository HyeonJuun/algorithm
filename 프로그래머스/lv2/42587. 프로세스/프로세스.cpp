#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    
    vector<int> mx;
    
    for(int i=0; i< priorities.size(); i++)
    {
        q.push({priorities[i], i});
        mx.push_back(priorities[i]);
    }
    sort(mx.begin(), mx.end(), greater<int>());
    int ind = 0;

    while(!q.empty())
    {
        int pri = q.front().first;
        if(q.front().first == mx[ind])
        {
            answer++;
            if(q.front().second == location)
                break;
            q.pop();
            ind++;
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
    return answer;
}