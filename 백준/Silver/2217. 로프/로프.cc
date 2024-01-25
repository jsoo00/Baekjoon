#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	vector<int>rope(N);
	vector<int>result_rope(N);
	for (int i = 0; i < N; i++) {
		cin >> rope[i];
	}
	sort(rope.begin(), rope.end(), greater<int>());
	for (int i = 0; i < N; i++) {
		result_rope.push_back((i + 1) * rope[i]);
	}
	cout << *max_element(result_rope.begin(), result_rope.end());
	return 0;
}