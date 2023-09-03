#include <string>
#include <vector>

using namespace std;

int answer = 0;
string target = "";
string check = "AEIOU";
bool findword = false;
void dfs(string str)
{
    if(str.length() > 5 || findword)
    {
        return;
    }
    
    if(str == target)
    {
        findword = true;
        return;
    }
    answer++;
    for(int i=0; i<check.length(); i++)
    {
        dfs(str + check[i]);
    }
}
int solution(string word) {
    target = word;
    
    dfs("");
    return answer;
}