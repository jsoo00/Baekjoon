#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(void){
	vector<int>n(10);
	for (int i = 0; i < 9; i++) {
		cin >> n[i];
	}
	cout << *max_element(n.begin(), n.end()) << '\n' << max_element(n.begin(), n.end()) - n.begin()+1;
	return 0;
}
