#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 1000

int n, ans;
int jump[MAX_N], dp[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> jump[i];
        dp[i] = INT_MIN;
    }
    dp[0] = 0;

    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(dp[j] == INT_MIN) continue;

            if(j+jump[j] >= i) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }

        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}