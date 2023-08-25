#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end(), greater<int>());
    int box = score.size() / m;
    int ind = 0;
    
    while(box--)
    {
        int pay = k;
        int count = 0;
        bool flag = true;
        for(int i=0; i<m; i++)
        {
            if(ind == score.size())
            {
                flag = false;
                break;
            }
            pay = min(pay, score[ind]);
            ind++;
        }
        if(!flag)
            break;
        else
        {
            answer += pay * m;
        }
    }
    return answer;
}