#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 1000

int n;
int nums[MAX_N], dp[MAX_N][2];

void Init() {
    for(int i=1; i<n; i++) {
        dp[i][0] = INT_MIN;
        dp[i][1] = INT_MIN;
    }

    dp[0][0] = 1;
    dp[0][1] = 1;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    Init();

    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            // 증가할 때
            if(dp[j][0] != INT_MIN && nums[j] < nums[i]) {
                dp[i][0] = max(dp[i][0], dp[j][0]+1);
            }

            // 감소할 때
            if(dp[j][1] != INT_MIN && nums[j] > nums[i]) {
                dp[i][1] = max(dp[i][1], dp[j][1]+1);
            }
        }

        // 증가하다 감소할 때
        dp[i][1] = max(dp[i][0], dp[i][1]);
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }

    cout << ans;

    return 0;
}