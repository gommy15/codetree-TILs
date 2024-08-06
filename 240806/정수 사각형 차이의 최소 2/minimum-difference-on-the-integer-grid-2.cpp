#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 100

int n;
int num[MAX_N][MAX_N], dp[MAX_N][MAX_N];

int ans = INT_MAX;

void Init() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            dp[i][j] = INT_MAX;
        }
    }

    dp[0][0] = num[0][0];

    for(int i=1; i<n; i++) {
        dp[i][0] = max(dp[i-1][0], num[i][0]);
        dp[0][i] = max(dp[0][i-1], num[0][i]);
    }
}

int Solve(int lower_bound) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(num[i][j] < lower_bound)
                num[i][j] = INT_MAX;
        }
    }

    Init();

    for(int i=1; i<n; i++) {
        for(int j=1; j<n; j++) {
            dp[i][j] = max(min(dp[i-1][j], dp[i][j-1]), num[i][j]);
        }
    }

    return dp[n-1][n-1];
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    
    int max_num = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> num[i][j];
            max_num = max(max_num, num[i][j]);
        }
    }

    for(int lower_bound = 1; lower_bound<=max_num; lower_bound++) {
        int upper_bound = Solve(lower_bound);

        if(upper_bound == INT_MAX) continue;

        ans = min(ans, upper_bound - lower_bound);
    }

    cout << ans;
    return 0;
}