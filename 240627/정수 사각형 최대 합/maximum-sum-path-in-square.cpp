#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

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
        dp[0][i] = dp[0][i-1] + grid[0][i];
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<n; j++) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + grid[i][j];
        }
    }

    cout << dp[n-1][n-1];
    return 0;
}