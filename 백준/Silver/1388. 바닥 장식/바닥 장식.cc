#include <iostream>
#include<string>
using namespace std;

char room[101][101];  //-나 |저장

int main(void) {
    int N, M; //세로, 가로
    cin >> N >> M;
    int result = 0; //판자의 개수

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
        }
    }

    for (int i = 0; i < N; i++) { //세로
        for (int j = 0; j < M; j++) { //가로  
            char shape1 = room[i][j]; //shape = -나 | 모양
            if (shape1 == '-') {
                if (room[i][j + 1] != '-') { //다음 행에 있는 것이 -가 아니라면    
                    result++; //나무판자개수+1           
                }
            }
        }
    }
    for (int i = 0; i < M; i++) { //가로
        for (int j = 0; j < N; j++) { //세로       
            char shape2 = room[j][i];
            if (shape2 == '|') {
                if (room[j + 1][i] != '|') {//다음 열에 있는 것이 |가 아니라면
                    result++; //나무판자개수+1              
                }
            }
        }
    }
    cout << result;
    return 0;
}