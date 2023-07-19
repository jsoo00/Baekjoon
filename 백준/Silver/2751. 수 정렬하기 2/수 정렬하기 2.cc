#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N,input;
	cin >> N;
	
	vector<int>num;
	for (int i = 0; i < N; i++) {
		cin >> input;
		num.push_back(input);
	}
	sort(num.begin(), num.end());

	for (int i = 0; i < N; i++) {
		cout << num[i] << '\n';
	}
	return 0;
}