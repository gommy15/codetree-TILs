#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n, l;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>l;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for(int a=1; a<MAX_N; a++) {
        int cnt_h = 0;
        int cnt_l = 0;

        for(int j=0; j<n; j++) {
            if(a <= arr[j]) cnt_h++;
            else if((a - arr[j]) == 1) {
                if(cnt_l < l) {
                    cnt_h++;
                    cnt_l++;
                }
            }
        }

        if(cnt_h >= a) {
            ans = a;
        }
    }

    cout << ans;
    return 0;
}