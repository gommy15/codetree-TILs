#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100
#define MAX_M 10000

int n, m;
int weight[MAX_N], value[MAX_N];
int dp[MAX_M+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=0; i<n; i++) {
        cin >> weight[i]>>value[i];
    }

    dp[0] = 0;

    for(int i=1; i<=m; i++) {
        for(int j=0; j<n; j++) {
            if(i < weight[j]) continue;

            dp[i] = max(dp[i], dp[i-weight[j]]+value[j]);
        }
    }

    cout << dp[m];
    return 0;
}