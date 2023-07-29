#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int alphabet[50];
string holsu, jjaksu;
int main()
{
    string s;
    cin >> s;
    for (char i : s)
    {
        alphabet[i]++; //배열에 각 알파벳의 개수 입력
    }
    for (char i = 'A'; i <= 'Z'; i++)
    {
        if (alphabet[i] % 2) //알파벳의 개수가 홀수이면
        {
            holsu += i; 
        }
        for (int j = 0; j < alphabet[i] / 2; j++)//알파벳의 개수를 2로 나누어 양 옆에 알파벳이 오도록함.
        {
            jjaksu += i; //일단 한 쪽만 알파벳을 붙임.
        }
    }
    if (holsu.size() > 1)
    {
        printf("I'm Sorry Hansoo");
    }
    else
    {
        cout << jjaksu; //위에서 2로 나누었으므로 여기서 출력하고 마지막에 한 번 더 짝수를 출력할거임.
        cout << holsu; //홀수 개의 알파벳들은 가운데에 오도록함.
        reverse(jjaksu.begin(), jjaksu.end()); //반대로 출력해서 대칭이 되게 함
        cout << jjaksu;
    }
}