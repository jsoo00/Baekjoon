# include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N,M;
	int count=0;
	int sum = 0;
	cin >> N >> M;
	vector<int>A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			sum += A[j];
			if (sum == M) {
				count += 1;
				sum = 0;
				break;
			}
			else if (sum > M) {
				sum = 0;
				break;
			}
		}
		sum = 0;
	}
	cout << count;

	return 0;
}
