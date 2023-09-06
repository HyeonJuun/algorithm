#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

struct TRIE
{
    int count = 0;
    unordered_map<char, TRIE*> child;
    
    void Insert(string str)
    {
        TRIE* now = this;
        for(int i=0; i<str.length(); i++)
        {
            if(now->child[str[i]] == nullptr)
            {
                now->child[str[i]] = new TRIE;
            }
            now = now->child[str[i]];
            now->count++;
        }
    }
    
    int AutoComplete(string str)
    {
        int input = 1;
        TRIE* now = child[str[0]];
        for(int i=1; i<str.length(); i++)
        {
            if(now->count > 1)
                input++;
            now = now->child[str[i]];
        }
        return input;
    }
};
int solution(vector<string> words) {
    int answer = 0;
    
    TRIE root;
    
    for(string word : words)
        root.Insert(word);
    
    for(string word : words)
        answer += root.AutoComplete(word);
    
    
    return answer;
}