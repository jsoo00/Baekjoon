#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    double V,A,B,result;
    cin >> A >> B >> V;
    result = (V - A) / (A - B);
    if (V - A == 0) {
        result = 0;
    }

    cout << (int)(ceil(result))+1;
    return 0;
} 