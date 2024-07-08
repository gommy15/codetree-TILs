#include <iostream>
using namespace std;
#define MAX_N 45

// Memoization
int n;
int memo[MAX_N+1];

int Fibo(int num) {
    if(memo[num] != 0)
        return memo[num];
    else if (num == 1 || num == 2)
        memo[num] = 1;
    else
        memo[num] = Fibo(num-1) + Fibo(num-2);

    return memo[num];
}

int main() {
    cin>> n;

    cout << Fibo(n);
}







// tabulation
// int n;
// int dp[MAX_N+1];

// int main() {
//     // 여기에 코드를 작성해주세요.
//     cin >> n;

//     dp[1] = 1;
//     dp[2] = 1;

//     for(int i=3; i<=n; i++) {
//         dp[i] = dp[i-1] + dp[i-2];
//     }

//     cout << dp[n];
//     return 0;
// }