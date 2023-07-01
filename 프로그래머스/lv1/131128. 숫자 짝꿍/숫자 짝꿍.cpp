#include <string>
#include <vector>

using namespace std;

int X_num[10];
int Y_num[10];
string solution(string X, string Y) {
    string answer = "";
    int ans = 0;
    for(int i=0; i<X.length(); i++)
        X_num[X[i] - '0']++;
    for(int i=0; i<Y.length(); i++)
        Y_num[Y[i] - '0']++;
    
    for(int i=9; i>=0; i--)
    {
        if(X_num[i] > 0 && Y_num[i] > 0)
        {

            while(X_num[i] > 0 && Y_num[i] > 0)
            {
                X_num[i]--;
                Y_num[i]--;
                answer += i + '0';
            if(i == 0 && answer.length() == 1)
                break;
            }
        }
    }
    if(answer.length() == 0)
        answer = "-1";
    return answer;
}