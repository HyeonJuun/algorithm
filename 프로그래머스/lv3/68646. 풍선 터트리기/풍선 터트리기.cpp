#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1000001;

int leftMin[MAX], rightMin[MAX];

int solution(vector<int> a) {
    int answer = 0;
    
    leftMin[0] = a[0];
    for(int i=1; i<a.size() - 1; i++)
    {
        leftMin[i] = min(leftMin[i-1], a[i]);
    }
    rightMin[a.size()-1] = a[a.size()-1];
    for(int i = a.size()-2; i>0; i--)
        rightMin[i] = min(rightMin[i+1], a[i]);
    
    for(int i=0; i<a.size(); i++)
    {
        if(i ==0 || i==a.size()-1)
        {
            answer++;
            continue;
        }
        if(a[i] < leftMin[i-1] || a[i] < rightMin[i+1])
            answer++;
    }
    return answer;
}