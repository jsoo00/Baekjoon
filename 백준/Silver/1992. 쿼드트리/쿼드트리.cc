#include <iostream>
#include <string>
using namespace std;

string number[64];

void quadTree(int N,int y, int x) {
	char num = number[y][x];

	for (int i = y; i < y + N; i++) {
		for (int j = x; j < x + N; j++) {
			if (number[i][j] != num) { //만약 값이 달라지면
				cout << '(';
				quadTree(N / 2, y, x);
				quadTree(N / 2, y, x+N/2);
				quadTree(N / 2, y+N/2, x);
				quadTree(N / 2, y+N/2, x+N/2);
				cout << ')';
				return;
			}
		}
	}
	cout << num; //처음 값
}


int main(void) {
	int N;
	cin >> N;
	//vector<string>v;

	for (int i = 0; i < N; i++) {
		cin >> number[i];
		//v.push_back(number);  //v[0][0]; //char
	}
	quadTree(N, 0, 0);
	
	return 0;
}