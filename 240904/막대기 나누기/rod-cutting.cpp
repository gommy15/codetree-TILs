#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100

int n;
int l_value[MAX_N+1], dp[MAX_N+1];

// void Init() {
//     for(int i=0; i<=n; i++) {
//         dp[i] = INT_MIN;
//     }

//     dp[0] = 0;
// }

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> l_value[i];
    }

    // Init();
    dp[0] = 0;

    for(int i=1; i<=n; i++) {
        // dp[i] = l_value[i];
        for(int j=1; j<=i; j++) {
            dp[i] = max(dp[i], dp[i-j]+l_value[j]);
        }
    }

    int ans = 0;

    for(int i=1; i<=n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;

}