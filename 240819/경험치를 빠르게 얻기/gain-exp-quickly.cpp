#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100
#define MAX_T 10000

int n, m, t;
int exp[MAX_N+1], runtime[MAX_N+1];
int dp[MAX_N+1][MAX_T+1];

void Init() {
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=t; j++) {
            dp[i][j] = INT_MIN;
        }
    }

    dp[0][0] = 0;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=1; i<=n; i++) {
        cin >> exp[i]>>runtime[i];
        t += runtime[i];
    }

    Init();

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=t; j++) {
            // 퀘스트를 진행했을 때
            if(j-runtime[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-runtime[i]]+exp[i]);
            
            // 퀘스트를 진행하지 않았을 때
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }

    int ans = INT_MAX;
    for(int j=0; j<=t; j++) {
        if(dp[n][j] >= m)
            ans = min(ans, j);
    }

    if(ans == INT_MAX)
        ans = -1;

    cout << ans;

    return 0;
}