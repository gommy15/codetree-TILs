#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 1000

int n;
int nums[MAX_N], dp[MAX_N][2];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    for(int i=0; i<n; i++) {
        // 해당 위치에서 새로 시작할 때
        dp[i][0] = 1;
        dp[i][1] = 1;
        for(int j=0; j<i; j++) {
            // 증가할 때
            if(nums[j] < nums[i]) {
                dp[i][0] = max(dp[i][0], dp[j][0]+1);
            }

            // 감소할 때
            if(nums[j] > nums[i]) {
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