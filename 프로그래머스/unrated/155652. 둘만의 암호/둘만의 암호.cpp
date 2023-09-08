#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i=0; i<s.length(); i++)
    {
        char c = s[i];
        for(int j=0; j<index; j++)
        {
            c++;
            if(c > 'z')
                c = 'a';
            for(int k=0; k<skip.length(); k++)
            {
                if(c == skip[k])
                    j--;
            }
        }
        
        answer += c;
    }
    return answer;
}