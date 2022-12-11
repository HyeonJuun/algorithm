#include <iostream>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
 
	int king = 1;
	int queen = 1;
	int rook = 2;
	int bishop = 2;
	int knight = 2;
	int pawn = 8;
 
	int in_king, in_queen, in_rook, in_bishop, in_knight, in_pawn;
 
	cin >> in_king;
	cin >> in_queen;
	cin >> in_rook;
	cin >> in_bishop;
	cin >> in_knight;
	cin >> in_pawn;
 
	cout << king - in_king << " ";
	cout << queen - in_queen << " ";
	cout << rook - in_rook << " ";
	cout << bishop - in_bishop << " ";
	cout << knight - in_knight << " ";
	cout << pawn - in_pawn << " ";
 
	return 0;
}