#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_DEV 5

int develop[MAX_DEV];

int main() {
    // 여기에 코드를 작성해주세요.
    int total_sum = 0;

    for(int i=0; i<MAX_DEV; i++){
        cin >> develop[i];
        total_sum += develop[i];
    }

    int min_diff = INT_MAX;
    bool possible = false;
    for(int i=0; i<MAX_DEV; i++){
        for(int j=0; j<MAX_DEV; j++){
            if(i == j) continue;
            for(int k=0; k<MAX_DEV; k++){
                if(k==i || k==j) continue;
                for(int l=0; l<MAX_DEV; l++){
                    if(l==i || l==j || l==k) continue;
                    int sum1 = develop[i] + develop[j];
                    int sum2 = develop[k] + develop[l];
                    int sum3 = total_sum - sum1 - sum2;
                    if(sum1 == sum2 || sum2 == sum3 || sum3 == sum1) continue;

                    int max_sum = max(sum1, max(sum2, sum3));
                    int min_sum = min(sum1, min(sum2, sum3));

                    min_diff = min(min_diff, (max_sum-min_sum));
                    possible = true;
                }
            }
        }
    }

    if(possible) cout << min_diff;
    else cout << -1;
    return 0;
}