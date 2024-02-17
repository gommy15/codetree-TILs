#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100

int n;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int min_sum = INT_MAX;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int remain_arr[MAX_N] = {};
            int diff_sum = 0;
            int cnt = 0;
            for(int k=0; k<n; k++) {
                if(k == j) continue;
                if(k==i) remain_arr[cnt++] = arr[k]*2;
                else remain_arr[cnt++] = arr[k];
            }

            for(int k=0; k<n-2; k++) {
                diff_sum += abs(remain_arr[k+1]-remain_arr[k]);
            }
            min_sum = min(min_sum, diff_sum);
        }
    }

    cout << min_sum;
    return 0;
}