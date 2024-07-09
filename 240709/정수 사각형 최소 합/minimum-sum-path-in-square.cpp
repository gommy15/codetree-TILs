#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n;
int num[MAX_N][MAX_N], dp[MAX_N][MAX_N];

void Init() {
    dp[0][n-1] = num[0][n-1];

    for(int i=1; i<n; i++) {
        dp[i][n-1] = dp[i-1][n-1] + num[i][n-1];
    }

    for(int j=n-2; j>=0; j--) {
        dp[0][j] = dp[0][j+1] + num[0][j];
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> num[i][j];
        }
    }

    Init();

    for(int i=1; i<n; i++) {
        for(int j=n-2; j>=0; j--) {
            dp[i][j] = min(dp[i-1][j], dp[i][j+1]) + num[i][j];
        }
    }

    cout << dp[n-1][0];
    return 0;
}