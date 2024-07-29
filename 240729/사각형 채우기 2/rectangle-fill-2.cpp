#include <iostream>
using namespace std;
#define MAX_N 1000
#define MOD 10007

int n;
long long dp[MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;

    for(int i=3; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]*2)%MOD;
    }

    cout << dp[n];
    return 0;
}