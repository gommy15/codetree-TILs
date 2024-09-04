#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100
#define MAX_M 10000

int n, m;
int seq[MAX_N];
bool dp[MAX_M+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=0; i<n; i++) {
        cin >> seq[i];
    }

    dp[0] = true;

    for(int i=0; i<n; i++) {
        for(int j=m; j>0; j--) {
            if(j-seq[i] < 0) continue;
            if(dp[j-seq[i]] == false) continue;

            dp[j] = true;
        }
    }

    if(dp[m]) cout << "Yes";
    else cout << "No";

    return 0;
}