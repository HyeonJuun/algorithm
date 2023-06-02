#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;


int solution(int x, int y, int n) {
    int answer = 987654321;
    bool flag = false;
    set<int> ck_num;
    queue<pair<int, int>> q;
    q.push({x, 0});
    
    while(!q.empty())
    {
        int curx = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(curx == y)
        {
            answer = dist;
            break;
        }
        if(curx < y)
        {
            if(ck_num.find(curx + n) == ck_num.end())
            {
                q.push({curx + n, dist + 1});
                ck_num.insert(curx + n);  
            }
            if(ck_num.find(curx * 2) == ck_num.end())
            {
                q.push({curx * 2, dist + 1});
                ck_num.insert(curx * 2);
            }
            if(ck_num.find(curx * 3) == ck_num.end())
            {
                q.push({curx * 3, dist + 1});
                ck_num.insert(curx * 3);            
            }
        }
        
    }
    if(answer == 987654321)
        answer = -1;
    return answer;
}