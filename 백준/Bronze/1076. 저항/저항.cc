#include <iostream>
#include <cstring>
using namespace std;

int setValue(char* color) {
	int num = 0;

	if (!strcmp(color, "black")) num = 0;
	else if (!strcmp(color, "brown")) num = 1;
	else if (!strcmp(color, "red")) num = 2;
	else if (!strcmp(color, "orange")) num = 3;
	else if (!strcmp(color, "yellow")) num = 4;
	else if (!strcmp(color, "green")) num = 5;
	else if (!strcmp(color, "blue")) num = 6;
	else if (!strcmp(color, "violet")) num = 7;
	else if (!strcmp(color, "grey")) num = 8;
	else if (!strcmp(color, "white")) num = 9;
	
	return num;
}

int setMul(char* color) {
	int num = 0;

	if (!strcmp(color, "black")) num = 1;
	else if (!strcmp(color, "brown")) num = 10;
	else if (!strcmp(color, "red")) num = 100;
	else if (!strcmp(color, "orange")) num = 1000;
	else if (!strcmp(color, "yellow")) num = 10000;
	else if (!strcmp(color, "green")) num = 100000;
	else if (!strcmp(color, "blue")) num = 1000000;
	else if (!strcmp(color, "violet")) num = 10000000;
	else if (!strcmp(color, "grey")) num = 100000000;
	else if (!strcmp(color, "white")) num = 1000000000;

	return num;
}
int main() {
	char color1[10];
	char color2[10];
	char color3[10];
	int num1 = 0, num2 = 0;
	long long num3 = 0;
	cin >> color1;
	cin >> color2;
	cin >> color3;
	
	num1 = setValue(color1);
	num2 = setValue(color2);
	num3 = setMul(color3);

	cout << (num1 * 10 + num2) * num3;
	return 0;
}