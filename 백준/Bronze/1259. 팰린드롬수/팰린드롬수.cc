#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(void){
    string num;
    while (true) {
        cin >> num;
        vector<int>answer(num.size(),0);
        if (num == "0") {
            break;
        }
        for (int i = 0; i < num.size() / 2; i++) {
            if (num[i] == num[num.size() - 1 - i]) {
                continue;
            }
            else { 
                answer[i] =1;
            }
        }
        if (*max_element(answer.begin(), answer.end()) == 1) {
            cout << "no"<<'\n';
        }
        else {
            cout << "yes"<<'\n';
        }
    }
    return 0;
}