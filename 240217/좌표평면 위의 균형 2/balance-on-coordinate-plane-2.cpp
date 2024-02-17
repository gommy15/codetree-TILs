/*
x=1, y=2 두 선이라고 했을 때,
1사분면 x<x1 && y<y1
2사분면 x>x1 && y<y1
3사분면 x>x1 && y>y1
4사분면 x<x1 && y>y1
*/

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100
#define MAX_XY 100

int n;
int x1[MAX_N], y1[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int max_x=0, max_y=0;
    for(int i=0; i<n; i++) {
        cin >> x1[i] >> y1[i];
        // max_x = max(max_x, x1[i]);
        // max_y = max(max_y, y1[i]);
    }

    int ans = INT_MAX;
    for(int x=2; x<=MAX_XY; x += 2) {
        for(int y=2; y<=MAX_XY; y += 2) {
            int cnt1=0, cnt2=0, cnt3=0, cnt4=0;

            for(int i=0; i<n; i++) {
                if(x < x1[i] && y < y1[i]) cnt1++;
                else if (x > x1[i] && y < y1[i]) cnt2++;
                else if (x > x1[i] && y > y1[i]) cnt3++;
                else cnt4++;
            }

            int max_cnt = max(cnt1, cnt2);
            max_cnt = max(max_cnt, cnt3);
            max_cnt = max(max_cnt, cnt4);

            ans = min(ans, max_cnt);
        }
    }

    cout << ans;
    return 0;
}