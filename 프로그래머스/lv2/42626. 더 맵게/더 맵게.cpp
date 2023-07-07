#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<scoville.size(); i++)
        pq.push(scoville[i]);
    
    while(pq.size() > 1 && pq.top() < K)
    {
        int mn_food = pq.top();
        pq.pop();
        int mn2_food = pq.top();
        pq.pop();
        
        int nx_food = mn_food + (mn2_food * 2);
        pq.push(nx_food);
        answer++;
    }
    if(pq.top() < K)
        answer = -1;
    return answer;
}