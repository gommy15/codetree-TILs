#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100
#define MAX_M 10000
#define MAX_ANS 10001

int dp[MAX_M+1];
int n, m;
int coin[MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for (int i=1; i<=n; i++) {
        cin >> coin[i];
    }

    for(int i=0; i<=m; i++) {
        dp[i] = MAX_ANS;
    }

    dp[0] = 0;

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(i>=coin[j]){
                dp[i] = min(dp[i], dp[i-coin[j]]+1);
            }
        }
    }

    int min_cnt = dp[m];

    if(min_cnt == MAX_ANS){
        min_cnt = -1;
    }

    cout << min_cnt;
    return 0;
}