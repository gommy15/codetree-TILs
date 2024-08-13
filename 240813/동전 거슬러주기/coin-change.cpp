#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100
#define MAX_M 10000

int n, m;
int coin[MAX_N], dp[MAX_M+1];

void Init() {
    for(int i=1; i<=m; i++) {
        dp[i] = INT_MAX;
    }

    dp[0] = 0;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    for(int i=0; i<n; i++) {
        cin >> coin[i];
    }

    Init();
    // sort(coin, coin+n);


    for(int i=1; i<=m; i++) {
        for(int j=0; j<n; j++){
            if(i < coin[j]) break;
            if(dp[i-coin[j]] == INT_MAX) continue;

            dp[i] = min(dp[i], dp[i-coin[j]]+1);
        }
    }

    if(dp[m] == INT_MAX) cout << -1;
    else cout << dp[m];
    return 0;
}