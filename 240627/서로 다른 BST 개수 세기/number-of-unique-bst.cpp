#include <iostream>
#define MAX_N 19
using namespace std;

int n;
int dp[MAX_N+1];

int NumOfUniqueBST(int cnt) {
    int number_of_unique_bst = 0;

    for(int i=0; i<cnt; i++) {
        number_of_unique_bst += dp[i] * dp[cnt-i-1];
    }

    return number_of_unique_bst;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = NumOfUniqueBST(i);
    }

    cout << dp[n];

    return 0;
}