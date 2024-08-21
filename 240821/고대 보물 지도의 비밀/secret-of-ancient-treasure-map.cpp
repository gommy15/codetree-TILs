#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100000
#define MAX_K 10

int n, k;
int nums[MAX_N+1], dp[MAX_N+1][MAX_K+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>k;

    for(int i=1; i<=n; i++) {
        cin >> nums[i];
    }

    int ans = INT_MIN;

    for(int i=1; i<=n; i++) {
        if(nums[i] >= 0) {
            for(int j=0; j<=k; j++) {
                dp[i][j] = max(dp[i-1][j] + nums[i], dp[i][j]);
                ans = max(ans, dp[i][j]);
            }
        }

        else {
            for(int j=1; j<=k; j++) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+nums[i]);
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans;
    return 0;
}