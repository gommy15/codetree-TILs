#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100
#define MAX_M 100000
#define OFFSET 100000

int n, m;
int arr[MAX_N+1];
int dp[MAX_N+1][MAX_M+1+OFFSET];

void Init() {
    for(int i=0; i<=n; i++) {
        for(int j=-m; j<=m; j++) {
            dp[i][j+OFFSET] = INT_MIN;
        }
    }

    dp[0][0+OFFSET] = 0;
}

void Update(int i, int j, int prev_i, int prev_j, int val) {
    if(prev_j < -m || prev_j > m || dp[prev_i][prev_j+OFFSET] == INT_MIN) return;

    dp[i][j+OFFSET] = max(dp[i][j+OFFSET], dp[prev_i][prev_j+OFFSET]+val);
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        m += arr[i];
    }

    for(int i=1; i<=n; i++) {
        for(int j=-m; j<=m; j++) {
            // 그룹 A에 i번째 원소를 추가하여 그룹A - 그룹B가 j가 된 경우
            Update(i, j, i-1, j-arr[i], arr[i]);

            // 그룹 B에 i번째 원소를 추가하여 그룹A-그룹B가 j가 된 경우
            Update(i, j, i-1, j+arr[i], 0);

            // 그룹 C에 i번째 원소를 추가하여 그룹A-그룹B가 j가 된 경우
            Update(i, j, i-1, j, 0);
        }
    }

    cout << dp[n][0+OFFSET];

    return 0;
}