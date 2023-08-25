#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    for(int i=0; i<n; i++)
        v.push_back(-1);
    for(int i=0; i<n; i++)
        v.push_back(1);
    
    do{
        int sum =0;
        answer++;
        
        for(int i=0; i < 2 * n; i++)
        {
            sum += v[i];
            if(sum < 0)
            {
                answer--;
                break;
            }
        }
    }while(next_permutation(v.begin(), v.end()));
    
    return answer;
}