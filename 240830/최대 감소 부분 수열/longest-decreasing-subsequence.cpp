#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 1000

int n;
int nums[MAX_N+1], dp[MAX_N+1];

void Init() {
    for(int i=1; i<=n; i++) {
        dp[i] = INT_MIN;
    }

    dp[0] = 0;
    nums[0] = INT_MAX;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> nums[i];
    }

    Init();

    for(int i=1; i<=n; i++) {
        for(int j=0; j<i; j++) {
            if(dp[j] == INT_MIN) continue;

            if(nums[j] > nums[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }

    int ans = 0;

    for(int i=1; i<=n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}