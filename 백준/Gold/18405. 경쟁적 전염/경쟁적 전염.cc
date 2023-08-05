#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K, S, X, Y;//시험관 크기, 바이러스크기, 시간, 좌표
int map[201][201]; //바이러스 입력받을 맵
bool visited[201][201]; //방문 표시
int xarr[4] = { 0,0,1,-1 }; //상하좌우
int yarr[4] = { 1,-1,0,0 };
struct virus_info { int x; int y; int num; };//바이러스 좌표와 크기 저장
vector<virus_info>next_virus;//4방향으로 탐색을 진행하는 후보들 담는 벡터

void input() {//입력하는 함수
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) { //0이 아니면 방문된 것으로 표시
				visited[i][j] = true;
			}
		}
	}
	cin >> S >> X >> Y;
}
bool compare(virus_info a, virus_info b) {//바이러스를 번호 순대로 sort 해주기 위한 함수
	if (a.num < b.num)return true;
	else return false; 
}
void infection(int x, int y) {//4방향으로 탐색
	for (int i = 0; i < 4; i++) {
		if (x + xarr[i] >= 0 && x + xarr[i] < N && y + yarr[i] >= 0 && y + yarr[i] < N && visited[x + xarr[i]][y + yarr[i]] == false) {
			//방문하지 않았고 틀 안에 있으면
			map[x + xarr[i]][y + yarr[i]] = map[x][y]; //전염시작
			visited[x + xarr[i]][y + yarr[i]] = true; //방문한 것으로 표시
		}
	}
}
void nextVirusSet() { //바이러스map을 탐색해서 바이러스를 set에 넣어둔다
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0) { //번호가 안 써진 곳이라면
				virus_info tmp;
				tmp.x = i; tmp.y = j; tmp.num = map[i][j];
				next_virus.push_back(tmp); //번호가 안써진 곳을 자식노드로 탐색
			}
		}
	}
}
void searchvirus(int s, int x, int y) {
	int second = 0;
	while (1) {
		if (map[x - 1][y - 1] != 0) { cout << map[x - 1][y - 1]; break; } //이미 번식하고 있는 바이러스가 있으면 거기에 다른 바이러스가 올수 없으므로 바로 출력
		if (second == s) { cout << 0; break; } //시간에 맞았는데 위에 if문에 안 걸렸다는 뜻이므로 0 출력
		next_virus.clear();
		nextVirusSet();
		sort(next_virus.begin(), next_virus.end(), compare); //set을 정렬한다(오름차순) 낮은 바이러스부터 번식을 시작하므로
		for (int i = 0; i < next_virus.size(); i++) {
			infection(next_virus[i].x, next_virus[i].y);
		}
		second++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	searchvirus(S, X, Y);
	return 0;
}