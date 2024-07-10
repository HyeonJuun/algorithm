#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int n;
int main(int argc, char **argv){
  std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

  cin >> n;
  vector<pair<pair<int, int>, pair<int, string>> > student(n); 
  // 년, 월, 일, 이름

  for(int i=0; i<n; i++){
    cin >> student[i].second.second >> student[i].second.first >> 
    student[i].first.second >> student[i].first.first;
  }

  sort(student.begin(), student.end()); // 년월일 순 정렬

  cout << student[n-1].second.second << "\n" << student[0].second.second;

  return 0;
}