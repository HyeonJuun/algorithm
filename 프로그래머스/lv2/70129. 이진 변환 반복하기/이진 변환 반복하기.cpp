#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int zeroCnt = 0, oneCnt, ans = 0;
    string tmp;
    
    while(s.length() != 1)
    {
        oneCnt = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '0')
            {
                zeroCnt++;
            }
            else
            {
                oneCnt++;
            }
        }
        s.clear();
        stack<int> st;
        while(oneCnt != 0)
        {
            st.push(oneCnt % 2);
            oneCnt /= 2;
        }
        
        while(!st.empty())
        {
            s += '0' + st.top();
            st.pop();
        }
        ans++;
    }
    answer.push_back(ans);
    answer.push_back(zeroCnt);
    return answer;
}