#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100
#define MAX_M 10000

int n, m;
int nums[MAX_N], dp[MAX_M+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    dp[0] = 1;

    for(int i=0; i<n; i++) {
        for(int j=m; j>0; j--) {
            if(j < nums[i]) continue;
            if(dp[j-nums[i]] == 0) continue;

            dp[j] = max(dp[j], 1);
        }
    }

    if(dp[m] == 0) cout << "No";
    else cout << "Yes";
    return 0;
}