#include <iostream>
#include <vector>
using namespace std;
vector <int> num;

void binary(int n) { //이진수로 바꾸는 함수
	if (n > 1) {
		binary(n / 2);
	}
	num.push_back(n % 2);
}

bool isPowerOfTwo(int n) { //이진수인지 구분하는 함수
	if (n == 1) {
		return true;
	}
	else if (n % 2 != 0 || n == 0) {
		return false;
	}
	return isPowerOfTwo(n / 2);
}

int main(void) {
	int K; //개수
	int one=0; //1의 개수
	int maximum = 0;
	int minimum = 0;
	cin >> K;
	if (isPowerOfTwo(K)==true) {//이진수라면
		cout << K << ' ' << 0;
	}
	else {//이진수가 아니라면
		binary(K);
		for (int i = 0; i < size(num); i++) {
			if (num[i]==1) {
				maximum = max(i,maximum);
				minimum = min(i, minimum);
				one = maximum - minimum + 1;
			}
		}
		while (!isPowerOfTwo(K)) {
			K++;
		}
		cout<<K<<' '<< one;
	}
	return 0;
}