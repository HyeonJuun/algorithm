#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    
    for(int i=0; i<cookie.size() - 1; i++)
    {
        int leftSum = cookie[i];
        int rightSum = cookie[i+1];
        
        int l_ind = i;
        int r_ind = i+1;
        
        while(true)
        {
            if(leftSum == rightSum)
                answer = max(leftSum, answer);
            
            if(leftSum > rightSum)
            {
                if(r_ind + 1 == cookie.size())
                    break;
                rightSum += cookie[++r_ind];
            }
            else
            {
                if(l_ind-1 < 0)
                    break;
                leftSum += cookie[--l_ind];
            }
        }
    }
    return answer;
}