#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100000

int n;
int nums[MAX_N], dp[MAX_N];

void Init() {
    for(int i=1; i<n; i++) {
        dp[i] = INT_MIN;
    }

    dp[0] = nums[0];
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    Init();

    for(int i=1; i<n; i++) {
        dp[i] = max(dp[i-1]+nums[i], nums[i]);
    }

    int ans = INT_MIN;

    for(int i=0; i<n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}