#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 1000

int n;
int a[MAX_N], b[MAX_N], dp[MAX_N+1][MAX_N+1];
int ans;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    for(int i=0; i<n; i++) {
        cin >> b[i];
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(dp[i][j] == -1) continue;

            if(a[i+1] < b[j+1])
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            
            if(a[i+1] > b[j+1])
                dp[i][j+1] = max(dp[i][j+1], dp[i][j]+b[j+1]);

            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
        }
    }

    int ans = 0;
    for(int i=0; i<=n; i++) {
        ans = max(ans, dp[i][n]);
        ans = max(ans, dp[n][i]);
    }
    
    cout << ans;
    
    return 0;
}