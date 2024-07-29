#include <iostream>
using namespace std;
#define MAX_N 1000
#define MOD 10007

int n;
int step[MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    step[0] = 1;
    step[1] = 0;
    step[2] = 1;
    step[3] = 1;

    for(int i=4; i<=n; i++) {
        step[i] = (step[i-2] + step[i-3])%MOD;
    }

    cout << step[n];
    return 0;
}