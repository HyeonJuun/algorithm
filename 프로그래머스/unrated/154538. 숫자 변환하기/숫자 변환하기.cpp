#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
int answer = 0;

int solution(int x, int y, int n) {
    set<int> st;
    queue<pair<int, int>> q;
    
    if(x == y)
        return 0;
    st.insert(x);
    q.push({x, 0});
    while(!q.empty())
    {
        int curx = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(curx == y)
        {
            answer = cnt;
            break;
        }
        else if(curx < y)
        {
            if(st.find(curx * 2) == st.end())
            {
                st.insert(curx * 2);
                q.push({curx * 2, cnt + 1});
            }
            if(st.find(curx * 3) == st.end())
            {
                st.insert(curx * 3);
                q.push({curx * 3, cnt + 1});
            }
            if(st.find(curx + n) == st.end())
            {
                st.insert(curx + n);
                q.push({curx + n, cnt + 1});
            }  
        }
    }
    if(answer == 0)
        answer = -1;
    return answer;
}