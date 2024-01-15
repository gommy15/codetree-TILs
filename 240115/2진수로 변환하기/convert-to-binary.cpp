#include <iostream>
using namespace std;

int n;
int digits[10000];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    
    int cnt = 0;
    while(true) {
        if(n <2) {
            digits[cnt++] = n;
            break;
        }

        digits[cnt++] = n%2;
        n /= 2;
    }

    for(int i=cnt-1; i >= 0; i--) {
        cout << digits[i];
    }
    return 0;
}