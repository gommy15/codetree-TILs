#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n;
int arr[MAX_N], s_arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        s_arr[i] = arr[i];
    }

    sort(s_arr, s_arr+n);
    int tmp[MAX_N] = {};
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(s_arr[i-1] != s_arr[i])
            tmp[cnt++] = s_arr[i];
    }

    if(cnt == 1) {
        cout << -1;
        return 0;
    }

    int sec_cnt = 0;
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == tmp[1]) {
            sec_cnt++;
            ans = i+1;
        }
    }

    if(sec_cnt > 1) cout << -1;
    else cout << ans;
    return 0;
}