#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int L, R;
	cin >> L >> R;
	string Ls = to_string(L);
	string Rs = to_string(R);
	int result = 0;

	for (int i = 0; i < Ls.size(); i++) {
		if (Ls.size() != Rs.size()) {//사이즈가 다를 때 ex)1800 18000 
			result = 0;
			break;
		}
		else if (Ls.size() == Rs.size()) {//사이즈가 같을 때 
			if (Ls[i] == '8' && Ls[i] == Rs[i]) { //1388 1389
				result++;
			}
			if ((i > 0) && (Ls[i - 1] != Rs[i - 1]) || (i > 0) && (Ls[i + 1] != Rs[i + 1])) {//1238 1338
				break;
			}
			if ((i == 0) && (Ls[0] != Rs[0]) || (i == 0) && (Ls[1] != Rs[1])) { //2000 3000 //2100 2200
				break;
			}
		}
		
	}

	cout << result;
	return 0;
}