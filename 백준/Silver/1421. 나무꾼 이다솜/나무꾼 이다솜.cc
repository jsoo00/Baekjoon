#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	//입력
	int N, C, W;//나무 개수, 자르는 비용, 나무 한 단위 가격
	cin >> N >> C >> W;

	int length;//나무 길이
	vector<int>length_arr; //나무 길이 저장할 벡터
	for (int i = 0; i < N; i++) {
		cin >> length;
		length_arr.push_back(length);
	}

	sort(length_arr.begin(), length_arr.end()); //오름차순 정렬
	int length_max = *max_element(length_arr.begin(), length_arr.end());//설정할 나무 길이 중 가장 긴 길이 = 입력한 나무길이들 중 최소값

	long long useful; //몫 = 자른 나무 수
	long long trash; //나머지 = 자르고 남은 것
	long long loss; //자르는 비용 총액
	long long gain; //팔고 번 돈
	long long result = 0; //가장 큰 이익 구하기 위한 변수

	for (int i = 1; i <= length_max; i++) { //자르는 단위
		long long total = 0; //총액
		for (int j = 0; j < N; j++) { //잘리는 나무
			if (length_arr[j] >= i) { //나누는 수보다는 크거나같아야 팔 수 있음
				useful = length_arr[j] / i;
				trash = length_arr[j] % i;

				if (trash == 0) { //나무가 남지 않았다면-> 몫-1 = 자르는데 든 횟수
					loss = C * (useful - 1);
				}
				else {//나무가 남았다면->몫 = 자르는데 든 횟수
					loss = C * useful;
				}

				//자른 나무들을 팔면
				gain = useful * W * i;

				if (gain - loss > 0) {// 자른 나무를 팔고 이익이 있어야함
					total += (gain - loss);
				}
			}
		}
		if (total > result) {
			result = total;
		}
	}
	cout << result;
	return 0;
}