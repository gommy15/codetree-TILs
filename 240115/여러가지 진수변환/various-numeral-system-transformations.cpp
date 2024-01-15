#include <iostream>
using namespace std;

int n, b;
int digits[1000];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>b;

    int cnt=0;
    while(true) {
        if(n < b) {
            digits[cnt++] = n;
            break;
        }

        digits[cnt++] = n%b;
        n /= b;
    }

    for(int i=cnt-1; i>=0; i--) {
        cout << digits[i];
    }
    return 0;
}