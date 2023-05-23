#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    // 자동으로 오름차순으로 정렬해주는 set + 기존의 set은 중복 제거하지만 multiset은 중복 허용
    multiset<int> input;
    for(int i=0; i<operations.size(); i++)
    {
        // Input 일때
        if(operations[i][0] == 'I')
        {
            string num = "";
            for(int j=2; j<operations[i].size(); j++)
            {
                num += operations[i][j];
            }
            //cout << num << " " << stoi(num) <<  endl;
            
            input.insert(stoi(num));
        }
        // Del
        else
        {
            if(input.empty())
                continue;
            
            //최대값 삭제
            if(operations[i][2] == '1')
            {
                //마지막 끝 부분의 위치를 받아온 후
                auto iter = input.end();
                // 그 전 자리가 삭제할 값의 위치
                iter--;
                //cout << *iter << endl;
                input.erase(iter);
            }
            //최소값 삭제
            else
            {
                //cout << *input.begin() << endl;
                input.erase(input.begin());
            }
        }
    }
    
    if(input.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        auto iter_max = input.end();
        auto iter_min = input.begin();
        iter_max--;
        answer.push_back(*iter_max);
        answer.push_back(*iter_min);
    }
    return answer;
}