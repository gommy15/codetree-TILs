#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000

int n;
int grid[MAX_N][MAX_N], dp[MAX_N][MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    dp[0][0] = grid[0][0];

    for(int i=1; i<n; i++) {
        dp[i][0] = min(dp[i-1][0], grid[i][0]);
        dp[0][i] = min(dp[0][i-1], grid[0][i]);
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<n; j++) {
            dp[i][j] = min(max(dp[i-1][j], dp[i][j-1]), grid[i][j]);
        }
    }

    cout << dp[n-1][n-1];

    return 0;
}