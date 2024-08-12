#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000
#define MAX_K 2

int n;
int nums[MAX_N], dp[MAX_N][MAX_K];
// 증가하는 중이면 dp의 j 값이 0 감소중이면 1

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    for(int i=0; i<n; i++) {
        // 현재 위치에서 시작하면 기본 세팅값은 1
        // 시작은 증가, 감소 모두 가능
        dp[i][0] = 1;
        dp[i][1] = 1;

        for(int j=0; j<i; j++) {
            // 증가만 할 때
            if(nums[j] < nums[i]) {
                dp[i][0] = max(dp[i][0], dp[j][0]+1);
            }

            // 감소만 할 때
           if(nums[j] > nums[i]) {
                dp[i][1] = max(dp[i][1], dp[j][1]+1);
           }
        }

        //증가하던 것을 멈추고 감소하는 것으로 변경될 경우
        dp[i][1] = max(dp[i][0], dp[i][1]);
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<MAX_K; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
    return 0;
}