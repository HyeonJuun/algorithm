#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if((s/n) < 1)
        answer.push_back(-1);
    else
    {
        for(int i=0; i<n; i++)
        {
            // if n = 3, s = 11
            // 3, 3, 5 / 3, 4, 4 
            // 45 / 48
            answer.push_back(s/n);
        }
        if(s % n != 0)
        {
            for(int i = 0; i< s % n; i++)
                answer[i] ++;
        }
        sort(answer.begin(), answer.end());
    }
    return answer;
}