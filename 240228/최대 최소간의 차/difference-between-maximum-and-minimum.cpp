#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100

int n, k;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>k;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int min_n = *min_element(arr, arr+n);
    int max_n = *max_element(arr, arr+n);

    int ans = INT_MAX;
    for(int a=min_n; a<=max_n; a++) {
        int cost = 0;

        for(int i=0; i<n; i++) {
            if(a <= arr[i] && arr[i] <= a+k) continue;
            if(arr[i] < a) {
                cost += (a-arr[i]);
            } else {
                cost += (arr[i]-a-k);
            }
        }

        ans = min(ans, cost);
    }

    cout << ans;
    return 0;
}