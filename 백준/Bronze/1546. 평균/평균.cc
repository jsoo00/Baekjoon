#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    double M,N;
    double sum = 0;
    double result;
    cin >> N;
    vector<double>score(N);
    vector<double>new_score(N);
    for (int i = 0; i < N; i++) {
        cin >> score[i];
    }
    M = *max_element(score.begin(), score.end());
    for (int i = 0; i < N; i++) {
        new_score[i] = score[i]/M*100;
        sum += new_score[i];
    }
    result = sum / N;
    cout << result;
    return 0;
}