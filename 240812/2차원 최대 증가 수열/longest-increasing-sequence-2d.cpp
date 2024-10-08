#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_NM 50

int n, m;
int dp[MAX_NM][MAX_NM], nums[MAX_NM][MAX_NM];

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
            cin >> nums[i][j];
        }
    }

    Init();

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int x=0; x<i; x++) {
                for(int y=0; y<j; y++) {
                    if(dp[x][y] == INT_MIN) continue;

                    if(nums[i][j] > nums[x][y]) {
                        dp[i][j] = max(dp[i][j], dp[x][y]+1);
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