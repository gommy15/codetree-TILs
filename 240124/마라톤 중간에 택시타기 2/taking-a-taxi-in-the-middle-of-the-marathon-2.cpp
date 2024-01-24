#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n;
pair<int, int> cp[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int x, y;
    for(int i=0; i<n; i++) {
        cin >> x>>y;
        cp[i] = make_pair(x, y);
    }

    int min_dis = INT_MAX;

    // 과거 좌표의 idx를 저장하는 방법
    for(int i=1; i<n-1; i++) {
        int dis = 0;
        int pre_idx = 0;
        for(int j=1; j<n; j++) {
            if(i==j) continue;
            dis += (abs(cp[pre_idx].first - cp[j].first) + abs(cp[pre_idx].second - cp[j].second));
            pre_idx = j;
        }
        min_dis = min(dis, min_dis);
    }



    // 과거 좌표를 저장하는 방법
    // for(int i=1; i<n-1; i++) {
    //     int dis = 0;
    //     int pre_x, pre_y, nxt_x, nxt_y;
    //     // cout << "check Point : " << cp[i].first << ' ' << cp[i].second << '\n';
    //     for(int j=0; j<n-1; j++) {
    //         if(i == j) continue;

    //         pre_x = cp[j].first;
    //         pre_y = cp[j].second;

    //         if(i == j+1) {
    //             nxt_x = cp[j+2].first;
    //             nxt_y = cp[j+2].second;
    //         }
    //         else {
    //             nxt_x = cp[j+1].first;
    //             nxt_y = cp[j+1].second;
    //         }

    //         dis += (abs(pre_x-nxt_x) + abs(pre_y-nxt_y));
    //         // cout << "Point : " << pre_x << ' ' << pre_y << ' ' << nxt_x << ' ' << nxt_y << '\n';
    //         // cout << "distence : " << dis << '\n';

    //     }

    //     min_dis = min(min_dis, dis);
    // }

    cout << min_dis;
    return 0;
}