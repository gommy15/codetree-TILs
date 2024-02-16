#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N   100

int n;
int h[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int max_h = 0;
    for(int i=0; i<n; i++) {
        cin >> h[i];
        max_h = max(max_h, h[i]);
    }

    int ans = 0;
    for(int k=0; k<=max_h; k++) {
        int tmp[MAX_N+1] = {};

        for(int i=0; i<n; i++) {
            if(h[i]-k > 0) tmp[i] = 1;
            else tmp[i] = 0;
        }

        int cnt = tmp[0];
        for(int i=1; i<n; i++) {
            if(tmp[i-1] == 0 && tmp[i] == 1) cnt++;
        }

        ans = max(ans, cnt);
    }

    cout << ans;
    return 0;
}