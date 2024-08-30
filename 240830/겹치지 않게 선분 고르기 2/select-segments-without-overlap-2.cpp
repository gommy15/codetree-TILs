#include <iostream>
#include <algorithm>
#include <climits>
#include <utility>
#include <tuple>
using namespace std;
#define MAX_N 1000

int n;
pair<int, int> lines[MAX_N];
int dp[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        int x1, x2;
        cin >> x1>>x2;
        lines[i] = make_pair(x1, x2);
    }

    sort(lines, lines+n);
    // dp[0] = 1;

    for(int i=0; i<n; i++) {
        // 첫 시작은 선분 1개
        dp[i] = 1;
        
        for(int j=0; j<i; j++) {
            int a2, b1;
            tie(ignore, a2) = lines[j];
            tie(b1, ignore) = lines[i];

            if(a2 < b1) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int ans = 0;

    for(int i=0; i<n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}