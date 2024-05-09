#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int gcd (int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    int maxGcd = -1;
    int temp;
    string line;
    string num;
    vector<int> v;

    cin >> t;
    cin.ignore();
    
    while (t--) {
        v.clear();
        maxGcd = -1;
        
        getline(cin, line);
        stringstream sstream(line);
        while (getline(sstream, num, ' ')) // 문자열 분리
            v.push_back(stoi(num));
        
        for (int i = 0; i < v.size() - 1; ++i) { // 완전탐색
            for (int j = i + 1; j < v.size(); ++j) {
                temp = gcd(v[i], v[j]);
                maxGcd = maxGcd < temp ? temp : maxGcd;
            }
        }
        cout << maxGcd << '\n';
    }
}