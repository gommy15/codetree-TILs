#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_NM 50

int n, m, ans;
int grid[MAX_NM][MAX_NM], dp[MAX_NM][MAX_NM];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
            dp[i][j] = INT_MIN;
        }
    }

    for(int i=0; i<n; i++) {
        dp[i][0] = 1;
        dp[0][i] = 1;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int r=0; r<i; r++) {
                for(int c=0; c<j; c++) {
                    if(grid[r][c] < grid[i][j]) {
                        dp[i][j] = max(dp[i][j], dp[r][c]+1);
                    }
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
    return 0;
}