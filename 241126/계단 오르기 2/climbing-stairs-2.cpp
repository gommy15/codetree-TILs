#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000
int n;
int coin[MAX_N+1], dp[MAX_N+1][4];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> coin[i];
    }

    dp[1][1] = coin[1];
    dp[2][0] = coin[2];
    dp[2][2] = coin[1]+coin[2];

    for(int i=3; i<=n; i++) {
        for(int j=0; j<=3; j++) {
            if(dp[i-2][j] != 0) {
                dp[i][j] = max(dp[i][j], dp[i-2][j] + coin[i]);
            }
            if(j && dp[i-1][j-1] != 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + coin[i]);
            }
        }
    }
    
    int ans = 0;
    for(int j=0; j<=3; j++) {
        ans = max(ans, dp[n][j]);
    }

    cout << ans;

    return 0;
}