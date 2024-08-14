#include <iostream>
#include <algorithm>
#include <climits>
#include <tuple>
using namespace std;
#define MAX_N 100

int n;
int dp[MAX_N+1], value[MAX_N+1];

void Init() {
    for(int i=1; i<=n; i++) {
        dp[i] = INT_MIN;
    }

    dp[0] = 0;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> value[i];
    }

    Init();

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            dp[i] = max(dp[i], dp[i-j]+value[j]);
        }
    }

    cout << dp[n];
    return 0;
}