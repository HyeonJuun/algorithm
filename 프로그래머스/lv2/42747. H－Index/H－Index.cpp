#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    int s = 0, e = 10000;
    
    while(s <= e)
    {
        int mid = (s + e) / 2;
        int cnt = 0;
        for(int i=citations.size() - 1; i>= 0 ;i--)
        {
            if(mid <= citations[i])
                cnt++;
            else
                break;
        }
        //cout << s << " " <<  mid << " " << e << " cnt : " << cnt << endl;
        
        if(cnt >= mid)
        {
            answer = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return answer;
}