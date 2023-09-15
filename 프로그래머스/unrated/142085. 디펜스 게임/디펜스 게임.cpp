#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int answer = 0;

int solution(int n, int k, vector<int> enemy) {
    
    priority_queue<int> pq;
    
    int i=0;
    for(; i<enemy.size(); i++)
    {
        if(n >= enemy[i])
        {
            n -= enemy[i];
            pq.push(enemy[i]);
        }
        else
        {
            if(k == 0)
            {
                break;
            }
            if(!pq.empty() && pq.top() > enemy[i])
            {
                n += pq.top();
                pq.pop();
                pq.push(enemy[i]);
                n -= enemy[i];
            }
            k--;
        }
    }
    return i;
}