#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100
#define MAX_M 100000

int n, m;
int nums[MAX_N+1];
bool dp[MAX_N+1][MAX_M+1];

void Init() {
    dp[0][0] = true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> nums[i];
        m += nums[i];
    }

    Init();

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            // i 번째 수를 선택해서 합이 j가 된 경우
            if(j >= nums[i] && dp[i-1][j-nums[i]])
                dp[i][j] = true;

            // i 번째 수를 선택하지 않고 합이 j가 된 경우
            if(dp[i-1][j])
                dp[i][j] = true;
        }
    }

    int ans = INT_MAX;
    for(int i=1; i<m; i++) {
        if(dp[n][i])
            ans = min(ans, abs(i-(m-i)));
    }

    cout << ans;
    return 0;
}