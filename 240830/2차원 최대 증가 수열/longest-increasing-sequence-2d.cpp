#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_NM 50

int n, m;
int nums[MAX_NM][MAX_NM], dp[MAX_NM][MAX_NM];

void Init() {
    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
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

    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            for(int a=0; a<i; a++) {
                for(int b=0; b<j; b++) {
                    if(dp[a][b] == INT_MIN) continue;

                    if(nums[a][b] < nums[i][j]) {
                        dp[i][j] = max(dp[i][j], dp[a][b]+1);
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
    return 0;
}