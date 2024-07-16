#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector <int> num(4);
	for (int i = 0; i < 3; i++)
	{
		int zero = 0;
		for (int i = 0; i < 4; i++)
		{
			cin >> num[i];
			if (num[i] == 0)
			{
				zero++;
			}
		}
		if (zero == 1) cout<<'A' << endl;
		else if (zero == 2) cout << 'B' << endl;
		else if (zero == 3) cout << 'C' << endl;
		else if (zero == 4) cout << 'D' << endl;
		else if (zero == 0) cout << 'E' << endl;
	}
}



