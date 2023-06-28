#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l_hand = 10, r_hand = 12;
    for(int i=0; i<numbers.size(); i++)
    {
        if(numbers[i] == 0)
        {
            numbers[i] = 11;
        }
        if(numbers[i] % 3 == 1)
        {
            answer += "L";
            l_hand = numbers[i];
        }
        else if(numbers[i] % 3 == 0)
        {
            answer += "R";
            r_hand = numbers[i];
        }
        else
        {
            int l_dist = (abs(l_hand - numbers[i]) % 3) + (abs(l_hand - numbers[i]) / 3);
            int r_dist = (abs(r_hand - numbers[i]) % 3) + (abs(r_hand - numbers[i]) / 3);
            if(l_dist > r_dist)
            {
                answer += "R";
                r_hand = numbers[i];
            }
            else if(l_dist < r_dist)
            {
                answer += "L";
                l_hand = numbers[i];
            }
            else
            {
                if(hand == "right")
                {
                    answer += "R";
                    r_hand = numbers[i];
                }
                else
                {
                    answer += "L";
                    l_hand = numbers[i];
                }
            }
        }
    }
    return answer;
}