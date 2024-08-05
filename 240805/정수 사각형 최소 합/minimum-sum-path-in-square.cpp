#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n;
int dp[MAX_N][MAX_N], nums[MAX_N][MAX_N];

void Init() {
    dp[0][n-1] = nums[0][n-1];

    for(int i=1; i<n; i++) {
        dp[i][n-1] = dp[i-1][n-1] + nums[i][n-1];
    }

    for(int i=n-2; i>=0; i--) {
        dp[0][i] = dp[0][i+1] + nums[0][i];
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> nums[i][j];
        }
    }

    Init();

    for(int i=1; i<n; i++) {
        for(int j=n-2; j>=0; j--){
            dp[i][j] = min(dp[i-1][j], dp[i][j+1]) + nums[i][j];
        }
    }

    cout << dp[n-1][0];

    return 0;
}