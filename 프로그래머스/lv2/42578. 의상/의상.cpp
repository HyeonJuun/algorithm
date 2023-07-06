#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    unordered_map<string, int> mp;
    for (vector<string> clothe : clothes)
        mp[clothe[1]]++;

    int answer = 1;
    for (auto it = mp.begin(); it != mp.end(); it++)
        answer *= it->second + 1;

    return answer - 1;
}