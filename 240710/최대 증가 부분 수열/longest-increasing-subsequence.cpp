#include <iostream>
using namespace std;
#define MAX_N 1000

int n;
int num[MAX_N+1], dp[MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> num[i];
    }

    dp[0] = 0;
    num[0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<i; j++) {
            if(num[j] < num[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }

    int ans = 0;
    for(int i=0; i<=n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}