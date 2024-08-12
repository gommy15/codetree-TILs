#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
#define MAX_N 1000

int n;
int dp[MAX_N];
tuple<int, int, int> info[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        int s, e, p;
        cin >> s>>e>>p;
        info[i] = make_tuple(s, e, p);
    }

    sort(info, info+n);

    for(int i=0; i<n; i++) {
        int s_i, p_i;
        tie(s_i, ignore, p_i) = info[i];
        dp[i] = p_i;

        for(int j=0; j<i; j++) {
            int e_j;
            tie(ignore, e_j, ignore) = info[j];

            if(e_j < s_i) {
                dp[i] = max(dp[i], dp[j]+p_i);
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