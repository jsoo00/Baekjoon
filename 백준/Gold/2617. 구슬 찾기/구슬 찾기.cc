#include <iostream>
#include <vector>
using namespace std;
//무게 정보를 보면 간선이 한 방향이기 때문에, 그래프 탐색을 <정방향>&<역방향>으로 한다.

int N, M; //구슬 개수, 저울에 올린 개수
vector<int> forward[100]; //정방향
vector<int> reverse[100]; //역방향
int light, heavy; //더 가벼운 거, 더 무거운 거
int forward_count = 0; //자기보다 가벼운 구슬의 개수 세는 것
int reverse_count = 0; //자기보다 무거운 구슬의 개수 세는 것
bool forward_check[100], reverse_check[100]; //방문 표시
int result = 0; //결과값

void forward_dfs(int num) {
	forward_check[num] = true; 
	for (int i = 0; i < ::forward[num].size(); i++) {
		int next = ::forward[num][i];  //인접 정점
		if (!forward_check[next]) {
			forward_count++;
			forward_dfs(next);
		}
	}
}

void reverse_dfs(int num) {
	reverse_check[num] = true;
	for (int i = 0; i < ::reverse[num].size(); i++) {
		int next = ::reverse[num][i];
		if (!reverse_check[next]) {
			reverse_count++;
			reverse_dfs(next);
		}
	}
}

void clear() { //초기화 함수
	forward_count = 0; 
	reverse_count = 0; 
	for (int i = 1; i <= N; i++) {
		forward_check[i] = false;
		reverse_check[i] = false;
	}
}

int main(void) {

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> heavy >> light;
		::forward[heavy].push_back(light);
		::reverse[light].push_back(heavy);
	}
	
	for (int i = 1; i <= N; i++) {
		clear();
		forward_dfs(i);
		reverse_dfs(i);
		
		//가벼운 구슬과 무거운 구슬의 개수가  (N+1)/2보다 커야 중간 구슬이 x.
		if (forward_count >= (N + 1) / 2 || reverse_count >= (N + 1) / 2) {
			result ++ ;
		}
	}
	
	cout << result;
	return 0;
}