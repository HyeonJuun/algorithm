#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int res = 0;
    sort(timetable.begin(), timetable.end());
    
    vector<int> tt;
    for(auto time : timetable)
    {
        tt.push_back(stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2)));
    }
    
    int ind = 0;
    int bus = 540;
    
    for(int i = 1; i<= n; i++)
    {
        int num = 0;
        while(num < m && ind < tt.size())
        {
            if(tt[ind] <= bus)
            {
                num++;
                ind++;
            }
            else
                break;
        }
        if(i == n)
        {
            if(num < m)
                res = bus;
            else
                res = tt[ind-1] - 1;
        }
        bus += t;
    }
    
    int h = res / 60;
    if(h <= 9)
    {
        answer += "0" + to_string(h) + ":";
    }
    else
        answer += to_string(h) + ":";
    
    
    int min = res % 60;
    if(min <= 9)
    {
        answer += "0" + to_string(min);
    }
    else
        answer += to_string(min);
    return answer;
}