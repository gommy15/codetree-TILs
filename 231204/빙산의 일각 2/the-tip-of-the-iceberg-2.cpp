#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100

int h[MAX_N];
int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int min_h = INT_MAX, max_h = INT_MIN;
    for(int i=0; i<n; i++) {
        cin >> h[i];
        min_h = min(min_h, h[i]);
        max_h = max(max_h, h[i]);
    }

    int cnt_max = INT_MIN;
    for(int i = min_h; i<max_h; i++) {
        int tmp[MAX_N] = {};
        for(int j=0; j<n; j++) {
            if(h[j] - i > 0) tmp[j] = 1;
            else tmp[j] = 0;
        }

        int cnt = tmp[0];
        for(int j=1; j<=n; j++) {
            if(tmp[j-1] != tmp[j]) cnt++;
        }

        cnt_max = max(cnt_max, (cnt/2));
    }

    cout << cnt_max;
    return 0;
}