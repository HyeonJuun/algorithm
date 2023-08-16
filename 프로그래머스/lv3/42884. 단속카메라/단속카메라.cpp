#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());
    int endPoint = routes[0][1];
    for(auto r : routes)
    {
        int sPoint = r[0];
        int ePoint = r[1];
        
        if(endPoint < sPoint)
        {
            answer++;
            endPoint = ePoint;
        }
        else
        {
            if(endPoint > ePoint)
            {
                endPoint = ePoint;
            }
        }
    }
    return answer;
}