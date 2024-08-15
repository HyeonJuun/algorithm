#include <vector>
#include <iostream>
using namespace std;
 
int main() {
	vector<int> music; //노래가 재생되는 과정을 벡터로 표현
	int N, L, D; //N은 앨범의 수록된 노래 수, L은 노래의 간격, D는 벨소리 간격
	int bell = 0; //벨소리는 0초에서 시작
 
	cin >> N >> L >> D;
 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < L; j++) { //노래가 재생되는 동안은
			music.push_back(1); //1을 벡터에 삽입
		}
		for (int j = 0; j < 5; j++) { //노래가 재생되지 않는 동안은
			music.push_back(0); //0을 벡터에 삽입
		}
	}
	
	while (1) {
		if (bell > music.size()) { //노래가 끝난 후 벨소리가 재생되면
			break; //탈출
		}
		if (music[bell] == 0) { //노래사이의 간격에 벨소리가 울리면
			break; //탈출
		}
		else { //벨소리는 D초 간격으로 울린다. 벨소리가 울리는 간격은 1초
			bell = bell + D;
		}
	}
	cout << bell;
}