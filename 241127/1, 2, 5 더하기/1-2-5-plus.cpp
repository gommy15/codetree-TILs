#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 1000
#define MAX_M 3
#define MOD 10007

int n;
int nums[MAX_M] = {1, 2, 5};
int dp[MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    dp[0] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<MAX_M; j++) {
            if(i-nums[j] >= 0) {
                dp[i] = (dp[i] + dp[i-nums[j]])%MOD;
            }
        }
    }

    cout << dp[n];
    return 0;
}