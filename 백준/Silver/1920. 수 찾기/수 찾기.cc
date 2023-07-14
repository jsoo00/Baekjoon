#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

int main(void) {
	int N, M;
	scanf("%d", &N); //N입력
	vector<int> A(N);//A입력
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	sort(A.begin(), A.end());//A 오름차순 정렬
	scanf("%d", &M);//M입력
	vector<int> B(M);//B입력
	for (int i = 0; i < M; i++) {
		scanf("%d", &B[i]);
	}
	vector<int> result; //출력 값
	
	for (int i = 0; i < M; i++) {//for문을 통해 숫자가 존재하는지 검사한다.
		int target = B[i];
	// binary_search(반복자.시작점, 반복자.끝점, 찾고자 하는 값); 찾으면 true를,  못 찾으면false.
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