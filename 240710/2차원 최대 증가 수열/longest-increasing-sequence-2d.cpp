#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_NM 50

int n, m;
int grid[MAX_NM][MAX_NM], dp[MAX_NM][MAX_NM];

void Init() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            dp[i][j] = INT_MIN;
        }
    }

    dp[0][0] = 1;
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n>>m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    Init();

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<i; k++) {
                for(int l=0; l<j; l++) {
                    if(dp[k][l] == INT_MIN) continue;

                    if(grid[k][l] < grid[i][j]) {
                        dp[i][j] = max(dp[i][j], dp[k][l]+1);
                    }
                }
            }
        }
    }

    int ans = INT_MIN;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
    return 0;
}