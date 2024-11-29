#include <iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

int n;
int profit[MAX_N + 1];

int dp[MAX_N + 1];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> profit[i];
    
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + profit[j]);
        }
    }

    cout << dp[n];
    
    return 0;
}