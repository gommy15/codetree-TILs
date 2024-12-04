#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 100
#define MAX_M 100000

int n, m;
int arr[MAX_N+1], dp[MAX_N+1][MAX_M+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> arr[i];
        m += arr[i];
    }

    dp[0][0] = true;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(j >= arr[i] && dp[i-1][j-arr[i]]) {
                dp[i][j] = true;
            }
            if(dp[i-1][j])
                dp[i][j] = true;
        }
    }

    int ans = INT_MAX;
    for(int i=1; i<=m; i++) {
        if(dp[n][i])
            ans = min(ans, abs(i-(m-i)));
    }
    cout << ans;
    return 0;
}