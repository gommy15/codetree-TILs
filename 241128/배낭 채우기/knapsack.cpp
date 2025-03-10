#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX_N 100
#define MAX_M 10000

int dp[MAX_N+1][MAX_M+1];
int n, m;
int weight[MAX_N+1], value[MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    for(int i=1; i<=n; i++) {
        cin >> weight[i] >> value[i];
    }

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            dp[i][j] = INT_MIN;
        }
    }

    dp[0][0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(j - weight[i] >= 0) {
                dp[i][j] = max(dp[i-1][j-weight[i]]+value[i], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int ans = 0;
    for(int i=0; i<=m; i++) {
        ans = max(ans, dp[n][i]);
    }

    cout << ans;
    return 0;
}