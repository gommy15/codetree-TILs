#include <iostream>
#include <algorithm>
#include <climits>
#include <tuple>
using namespace std;
#define MAX_N 1000

int n;
int dp[MAX_N];
pair<int, int> lines[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int x1, x2;
    for(int i=0; i<n; i++) {
        cin >> x1>>x2;
        lines[i] = make_pair(x1, x2);
    }

    sort(lines, lines+n);

    for(int i=0; i<n; i++) {
        dp[i] = 1;

        int x1_i;
        tie(x1_i, ignore) = lines[i];

        for(int j=0; j<i; j++) {
            int x2_j;
            tie(ignore, x2_j) = lines[j];

            if(x2_j < x1_i) {
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