#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000

int n;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    // 1. 3개의 수 모두 양수
    int ans = arr[n-1]*arr[n-2]*arr[n-3];

    //2. 2개 수 음수 & 1개 양수
    int mul = arr[0]*arr[1]*arr[n-1];
    ans = max(ans, mul);

    cout << ans;
    return 0;
}