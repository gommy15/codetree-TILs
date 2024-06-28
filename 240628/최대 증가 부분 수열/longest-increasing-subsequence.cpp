#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 1000

int n, ans;
int num[MAX_N+1], dp[MAX_N+1];

void Initialize() {
    for(int i=0; i<=n; i++) {
        dp[i] = INT_MIN;
    }

    dp[0] = 0;
    num[0] = 0;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> num[i];
    }
    Initialize();

    for(int i=1; i<=n; i++) {
        for(int j=0; j<i; j++) {
            if(num[j]<num[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    for(int i=0; i<=n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}