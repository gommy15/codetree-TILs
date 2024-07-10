#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000
#define MAX_K 2

int n;
int arr[MAX_N], dp[MAX_N][MAX_K];

// j==0 : 증가하는 수열 dp
// j==1 : 감소하는 수열 dp

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++) {
        dp[i][0] = 1;
        dp[i][1] = 1;

        for(int j=0; j<i; j++) {
            if(arr[j] < arr[i])
                dp[i][0] = max(dp[i][0], dp[j][0]+1);

            if(arr[j] > arr[i]) {
                dp[i][1] = max(dp[i][1], dp[j][1]+1);
            }
        }

        // 증가하다 감소하는 경우
        dp[i][1] = max(dp[i][1], dp[i][0]);
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