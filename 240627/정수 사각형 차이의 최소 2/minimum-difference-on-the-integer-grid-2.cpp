#include <iostream>
#include <algorithm>
#include <tuple>
#include <climits>
using namespace std;
#define MAX_N 100

int n;
int grid[MAX_N][MAX_N];
tuple<int, int, int> dp[MAX_N][MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    dp[0][0] = make_tuple(INT_MAX, grid[0][0], grid[0][0]);


    for(int i=1; i<n; i++) {
        int dif, max_num, min_num;
        tie(dif, max_num, min_num) = dp[i-1][0];

        max_num = max(max_num, grid[i][0]);
        min_num = min(min_num, grid[i][0]);
        dif = min(dif, abs(max_num - min_num));
        dp[i][0] = make_tuple(dif, max_num, min_num);

        tie(dif, max_num, min_num) = dp[0][i-1];

        max_num = max(max_num, grid[0][i]);
        min_num = min(min_num, grid[0][i]);
        dif = min(dif, abs(max_num - min_num));
        dp[0][i] = make_tuple(dif, max_num, min_num);
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<n; j++) {
            int dif1, max_num1, min_num1;
            tie(dif1, max_num1, min_num1) = dp[i-1][j];

            max_num1 = max(max_num1, grid[i][j]);
            min_num1 = min(min_num1, grid[i][j]);
            dif1 = min(dif1, abs(max_num1 - min_num1));

            int dif2, max_num2, min_num2;
            tie(dif2, max_num2, min_num2) = dp[i][j-1];

            max_num2 = max(max_num2, grid[i][j]);
            min_num2 = min(min_num2, grid[i][j]);
            dif2 = min(dif2, abs(max_num2 - min_num2));
            
            if(dif1 > dif2) {
                dp[i][j] = make_tuple(dif2, max_num2, min_num2);
            }else {
                dp[i][j] = make_tuple(dif1, max_num1, min_num1);
            }
        }
    }

    int ans;
    tie(ans, ignore, ignore) = dp[n-1][n-1];

    cout << ans;
    
    return 0;
}