#include <iostream>
using namespace std;
#define MAX_N 1000

int n;
int dp[MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for(int i=4; i<=n; i++) {
        dp[i] = (dp[i-2] + dp[i-3])%10007;
    }

    cout << dp[n];
    return 0;
}