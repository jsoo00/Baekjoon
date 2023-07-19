#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int>a, pair<int,int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else
		return a.first < b.first;
}

int main(void) {
	int N;
	cin >> N;

	pair<int, int>dot;
	vector<pair<int, int>>result;
	for (int i = 0; i < N; i++) {
		cin >> dot.first >> dot.second;
		result.push_back(dot);
	}

	sort(result.begin(), result.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << result[i].first << ' ' << result[i].second << '\n';
	}

	return 0;
}