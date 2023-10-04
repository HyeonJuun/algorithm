#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int checkTime[2000];

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    
    for(int i=0; i<book_time.size(); i++)
    {
        int start_h = stoi(book_time[i][0].substr(0, 2));
        int start_m = stoi(book_time[i][0].substr(3));
        int end_h = stoi(book_time[i][1].substr(0,2));
        int end_m = stoi(book_time[i][1].substr(3));
        
        int s = start_h * 60 + start_m;
        int m = end_h * 60 + end_m + 10;
        for(int t = s; t<m; t++)
            checkTime[t]++;
    }
    answer = *max_element(checkTime, checkTime + 2000);
    return answer;
}