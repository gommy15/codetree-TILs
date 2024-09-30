#include <iostream>
#include <string>
using namespace std;
#define MAX_N 200

string sen[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    int cnt = 0;

    while(true) {
        string str;
        cin >> str;
        if(str == "") break;

        sen[cnt] = str;
        cnt++;
    }

    for(int i=2; i<cnt; i=i+3) {
        cout << sen[i] << '\n';
    }
    return 0;
}