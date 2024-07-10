#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;
#define MAX_N 1000

int n;
pair<int, int> segments[MAX_N];
int dp[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<n; i++) {
        int x1, x2;
        cin >> x1>>x2;
        segments[i] = make_pair(x1, x2);
    }

    sort(segments, segments+n);

    for(int i=0; i<n; i++) {
        dp[i] = 1;

        for(int j=0; j<i; j++) {
            int x1_i, x2_j;
            tie(x1_i, ignore) = segments[i];
            tie(ignore, x2_j) = segments[j];

            if(x2_j < x1_i)
                dp[i] = max(dp[i], dp[j]+1);
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}