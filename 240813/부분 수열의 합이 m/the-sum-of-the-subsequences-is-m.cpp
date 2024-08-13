#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100
#define MAX_M 10000

int n, m;
int nums[MAX_N], dp[MAX_M+1];

void Init() {
    for(int i=1; i<=m; i++) {
        dp[i] = INT_MAX;
    }

    dp[0] = 0;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    Init();

    for(int i=0; i<n; i++) {
        for(int j=m; j>0; j--) {
            if(j < nums[i]) continue;
            if(dp[j-nums[i]] == INT_MAX) continue;

            dp[j] = min(dp[j], dp[j-nums[i]]+1);
        }
    }

    if(dp[m] == INT_MAX) cout << -1;
    else cout << dp[m];

    return 0;
}