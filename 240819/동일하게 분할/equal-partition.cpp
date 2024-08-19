#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100
#define MAX_S 100000

int n, m;
int nums[MAX_N+1];
bool dp[MAX_N+1][MAX_S+1];

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
            if(j >= nums[i] && dp[i-1][j-nums[i]])
                dp[i][j] = true;
            
            if(dp[i-1][j])
                dp[i][j] = true;
        }
    }

    int ans = INT_MAX;
    for(int i=1; i<m; i++) {
        // cout << dp[n][i] << '\n';
        if(dp[n][i])
            ans = min(ans, abs(i-(m-i)));
    }

    // cout << ans;
    if (ans == 0) cout << "Yes";
    else cout << "No";
    return 0;
}