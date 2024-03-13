#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_NM 100

int n, m;
int arr[MAX_NM][MAX_NM];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    // if(n==1 && m==1) {
    //     cout << 2;
    //     return 0;
    // }

    int ans = 0;
    // 각 행별로 확인하기
    for(int i=0; i<n; i++) {
        int cnt = 1, max_seq = 1;
        for(int j=1; j<n; j++) {
            if(arr[i][j-1] == arr[i][j]) cnt++;
            else cnt = 1;

            // n이 1이고 m도 1일때의 대비
            max_seq = max(max_seq, cnt);
        }

        if(max_seq >= m) ans++;
    }

    // cout << ans << '\n';

    // 각 열별로 확인하기
    for(int i=0; i<n; i++) {
        int cnt = 1, max_seq = 1;
        for(int j=1; j<n; j++) {
            if(arr[j-1][i] == arr[j][i]) cnt++;
            else cnt = 1;

            max_seq = max(max_seq, cnt);
        }
        if(max_seq >= m) ans++;
    }

    cout << ans;
    return 0;
}