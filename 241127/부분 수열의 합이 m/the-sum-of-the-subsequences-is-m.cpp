#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define MAX_M 10000
#define MAX_ANS 101

int n, m;
int arr[MAX_N], dp[MAX_M+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int i=1; i<=m; i++) {
        dp[i] = MAX_ANS;
    }

    dp[0] = 0;

    for(int i=0; i<n; i++) {
        for(int j=m; j>=0; j--) {
            if(j >= arr[i]) {
                dp[j] = min(dp[j], dp[j-arr[i]]+1);
            }
        }
    }

    if(dp[m] == MAX_ANS) cout << -1;
    else cout << dp[m];
    
    return 0;
}