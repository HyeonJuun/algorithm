#include <string>
#include <vector>
using namespace std;

int answer = 987654321;
bool visited[51];
 
void dfs(string begin, string target, vector<string> words, int cnt) {
    for (int i = 0; i < words.size(); i++) {
        int count = 0;
        for (int j = 0; j < words[i].length(); j++)
            
            if (!visited[i] && begin[j] != words[i][j])    
                count++;
        if (count == 1) {
            if (target == words[i] && answer > cnt + 1) {
                answer = cnt + 1;
                return;
            }
            
            visited[i] = true;
            dfs(words[i], target, words, cnt + 1);
            visited[i] = false;
        }
    }
}
 
int solution(string begin, string target, vector<string> words) {
    
    dfs(begin, target, words, 0);
    
    if (answer == 987654321)   
        answer = 0;
    
    return answer;
}