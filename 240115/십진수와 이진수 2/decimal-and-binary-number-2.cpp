#include <iostream>
#include <string>
using namespace std;

string binary;
int digits[30];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> binary;
    int num = 0;
    for(int i=0; i<binary.size(); i++) {
        num = num*2 + (binary[i] - '0');
    }

    num *= 17;

    int cnt = 0;
    while(true) {
        if(num < 2) {
            digits[cnt++] = num;
            break;
        }

        digits[cnt++] = num%2;
        num /= 2;
    }

    for(int i=cnt-1; i >= 0; i--) {
        cout << digits[i];
    }
    return 0;
}