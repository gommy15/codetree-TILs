#include <iostream>
using namespace std;
#define MAX_N 45

int fibo[MAX_N+1];
int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    fibo[0] = 1;
    fibo[1] = 1;
    fibo[2] = 1;

    for(int i=3; i<=n; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    cout << fibo[n];
    return 0;
}