#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<int,string>a, pair<int,string>b) {
	return a.first < b.first;
}

int main(void) {
	int N;
	cin >> N;

	pair<int, string> member;
	vector<pair<int, string>> result;

	for (int i = 0; i < N; i++) {
		cin >> member.first >> member.second;
		result.push_back(member);
	}
	stable_sort(result.begin(), result.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << result[i].first << ' ' << result[i].second << '\n';
	}

	return 0;
}