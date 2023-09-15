#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey > 0)
    {
        int mod = storey % 10;
        
        if(mod > 5)
        {
            answer += 10 - mod;
            storey /= 10;
            storey++;
        }
        else if( mod == 5)
        {
            int nxmod = (storey/10) % 10;
            if(nxmod >= 5)
            {
                storey /= 10;
                storey++;
            }
            else
                storey /= 10;
            answer += 5;
        }
        else
        {
            answer += mod;
            storey /= 10;
        }
    }
    return answer;
}