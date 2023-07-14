#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

int main(void) {
	int N, M;

	//N입력
	scanf("%d", &N);

	//A입력
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	//A 오름차순 정렬
	sort(A.begin(), A.end());


	//M입력
	scanf("%d", &M);

	//B입력
	vector<int> B(M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &B[i]);
	}

	//B 오름차순 정렬
	//sort(B.begin(), B.end());

	vector<int> result; //출력 값



	//for문을 통해 숫자가 존재하는지 검사한다.
	for (int i = 0; i < M; i++) {
		int target = B[i];

	// binary_search(반복자.시작점, 반복자.끝점, 찾고자 하는 값);
	//찾고자 하는 값을 찾으면 true를, 찾지 못하면 false를 반환한다.
		bool isFound = binary_search(A.begin(), A.end(), target);
			if (isFound) {
				result.push_back(1);
			}
			else {
					result.push_back(0);
			}
	}
	for (int i = 0; i < M; i++) {
		if (i < M - 1) {
			printf("%d\n", result[i]);
		}
		if (i == M - 1) {
			printf("%d", result[i]);
		}
	}
	return 0;
}