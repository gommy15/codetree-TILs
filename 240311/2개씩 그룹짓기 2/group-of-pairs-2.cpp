#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100000

int n;
int arr[MAX_N*2];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<2*n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+(2*n));

    int min_diff = INT_MAX;
    for(int i=0; i<n; i++) {
        // cout << arr[i] << ' ' << arr[i+n] << '\n';
        min_diff = min(min_diff, (arr[n+i]-arr[i]));
    }

    cout << min_diff;
    return 0;
}