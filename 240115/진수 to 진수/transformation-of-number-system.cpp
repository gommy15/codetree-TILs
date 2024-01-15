#include <iostream>
#include <string>
using namespace std;

string n;
int a, b;
int digits[20];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a>>b>>n;

    int num = 0;
    for(int i=0; i<n.size(); i++) {
        num = num*a + (n[i] - '0');
    }

    int cnt = 0;
    while(true) {
        if(num < b) {
            digits[cnt++] = num;
            break;
        }

        digits[cnt++] = num%b;
        num /= b;
    }

    for(int i=cnt-1; i >=0; i--) {
        cout << digits[i];
    }
    return 0;
}