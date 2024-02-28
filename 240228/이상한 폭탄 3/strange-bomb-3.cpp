#include <iostream>
#include <algorithm>
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

    int max_cnt = 0;
    int ans = 0;
    for(int i=0; i<n; i++) {
        int cnt = 0;
        int pre_idx = 0;
        int des_num = arr[i];
        for(int j=i+1; j<n; j++) {
            if(des_num == arr[j] && j-pre_idx <= k) {
                cnt++;
                pre_idx = j;
            }
        }

        if(max_cnt < cnt) {
            max_cnt = cnt;
            ans = des_num;
        }
    }

    cout << ans;
    return 0;
}